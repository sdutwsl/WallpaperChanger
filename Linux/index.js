const fs = require('fs')
const child_process = require('child_process')
const path = require('path')

const config_file_name = './Config.txt'
const pic_types = ["png", "jpeg", "jpg"]

let file_data = fs.readFileSync(config_file_name)
const configs = file_data.toString().split("\n")
const picture_dir = configs[0].split("=")[1]
const change_interval = parseInt(configs[1].split("=")[1])

let files = fs.readdirSync(picture_dir, { withFileTypes: true })
let picture_files = []
for (let f in files) {
    if (files[f].isDirectory()) {
        continue
    } else {
        let exts = files[f].name.split(".")
        let ext = exts[exts.length - 1]
        if (!pic_types.find(v => { return v === ext })) {
            continue
        } else {
            picture_files.push(files[f].name)
        }
    }
}
while (true) {
    for (let p in picture_files) {
        let current_picture = path.resolve(picture_dir, picture_files[p])
        console.log(current_picture)
        child_process.execSync("gsettings set org.gnome.desktop.background picture-uri file:" + current_picture)
        child_process.execSync("sleep " + change_interval)
    }
}

console.log("Finish")