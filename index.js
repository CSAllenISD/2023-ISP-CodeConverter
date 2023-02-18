var http = require('http');
var fs = require('fs');
var {exec, spawn, execSync} = require('child_process');

function convert(){
    var swiftC = document.getElementById('inputArea').value;
    var commands = execSync('touch temp-files/temps.txt');
    var textCommand2 = 'cat ' + swiftC.toString() + ' > temp-files/temps.txt';
    var command1 = execSync(textCommand2);
    var newCode = execSync('./Back\ End/main < temp-files/temps.txt');
    document.getElementById('outputArea').value = newCode.toString();
    var command3 = ('rm temp-files/temps.txt');
}