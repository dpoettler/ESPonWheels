let speedMultiplier = document.getElementById('speed-slider').value;

document.getElementById('speed-slider').addEventListener('change', function () {
    speedMultiplier = this.value;
    console.log('Speed multiplier set to ' + speedMultiplier);
    fetch('/set-speed?speed=' + encodeURIComponent(speedMultiplier));
});

function handleButtonHold(buttonId, message) {
    const button = document.getElementById(buttonId);
    const isMobile = /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(window.navigator.userAgent);

    if (isMobile) {
        button.addEventListener('touchstart', function () {
            console.log(message + ' button pressed');
            fetch('/' + buttonId + '/press');
        });

        button.addEventListener('touchend', function () {
            console.log(message + ' button released');
            fetch('/' + buttonId + '/release');
        });
    } else {
        button.addEventListener('mousedown', function () {
            console.log(message + ' button pressed');
            fetch('/' + buttonId + '/press');
        });

        button.addEventListener('mouseup', function () {
            console.log(message + ' button released');
            fetch('/' + buttonId + '/release');
        });
    }
};

function handleButtonClick(buttonId, message) {
    document.getElementById(buttonId).addEventListener('click', function () {
        console.log(message + ' button clicked');
        fetch('/' + buttonId);
    });
};

handleButtonHold('forward', 'Forward');
handleButtonHold('backward', 'Backward');
handleButtonHold('left', 'Left');
handleButtonHold('right', 'Right');
handleButtonHold('sfx3', 'Horn');

handleButtonClick('sfx0', 'SFX0');
handleButtonClick('sfx1', 'SFX1');