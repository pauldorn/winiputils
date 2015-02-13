var winiputils = require("./build/Release/winiputils");
var os = require('os');

if(process.argv.length < 3)  {
    console.log("Usage: test.js DEVICE");
    console.log("Valid Device formats: \\\\Device\\\\NPF_{F4E17724-C36B-4D85-BABA-48580F7A4EF5}");
    console.log("Valid Device formats: {F4E17724-C36B-4D85-BABA-48580F7A4EF5}");
} else {
    var device = process.argv[2].match(/{[^}]*}/)[0];
    console.log("Device GUID:  ", device);
    console.log("Device Friendly name: ", winiputils.GetInterfaceFriendlyName(device));

}
