const delay = ms => new Promise(res => setTimeout(res, ms));

const test = async() => {
    var testOne = document.getElementById("testOne");
    var oldContent = testOne.innerHTML;
    testOne.innerHTML = "Clicked!"
    await delay(1000);
    testOne.innerHTML = oldContent;
};