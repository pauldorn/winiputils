var winiputils = require("./build/Release/winiputils");
var os = require('os');
//console.log(os.networkInterfaces());
var device = "\\Device\\NPF_{F4E17724-C36B-4D85-BABA-48580F7A4EF5}".match(/{[^}]*}/)[0];
console.log(device);
console.log(winiputils.GetFriendlyName(device));
