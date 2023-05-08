//var http = require('http');
//var fs = require('fs');
var {exec, spawn, execSync} = require('child_process');

function convert(){
    var swiftC = document.getElementById('inputArea').value;
    var commands = execSync('touch temp-files/temps.txt');
    var textCommand2 = 'cat ' + swiftC.toString() + ' > temp-files/temps.txt';
    var command1 = execSync(textCommand2);
    var newCode = execSync('./Back\ End/main < temp-files/temps.txt');
    document.getElementById('outputArea').value = newCode.toString();
    var command3 = ('rm temp-files/temps.txt');
    console.log("Worked!")
}
darkModeOn = false;
const spawner = require('child_process').spawn;
function toggleDarkMode() {
  inner = { true: "Dark Mode", false: "Light Mode" };
  var element = document.body;
  db = document.getElementById("db");
  element.classList.toggle("darkMode");
  darkModeOn = !darkModeOn;
  db.innerHTML = inner[darkModeOn];
}

const express = require("express");
const app = express();
app.use(express.static("public"));

app.get('/', (req, res) => {
  res.sendFile('public/index.html');
})

app.listen(3000, function() {
  console.log("Running on port 3000.");
});
function fileUpload() {
    Array.prototype.forEach.call(document.querySelectorAll('.file-upload-button'), function (button) {
	const hiddnenInput = button.parentElement.querySelector('.file-upload-input');
	const label = button.parentElement.querySelector('.file-upload-label');
	const defualtLabelTest = 'No file selected';

	label.textContext = defaultLabelText;
	label.title = defaultLabelText;

	button.addEventListener('click', function() {
	    hiddenInput.click();
	});
    });

			       
}

function myFunction() {
    document.getElementById("myDropdown").classList.toggle("show");
}
/*

window.onclick = function(event) {
    if (!event.target.matches('.dropbtn')) {
	var dropdowns = document.getElementsByClassName("dropdown-content");
	var i;
	for (i = 0; i < dropdowns.length; i++) {
	    var openDropdown = dropdowns[i];
	    if (openDropdown.classList.contains('show')) {
		openDropdown.classList.remove('show');
	    }
	}
    }
}
*/
/*
function convert(text) {
    const swiftC = document.getElementById('inputArea').value;
    const pythonProcess = spawner('python', ['./index.py', JSON.stringify(swiftC)]);
    pythonProcess.stdout.on('data', (data) => {
        console.log(data.toString());
    });
}

var server
*/