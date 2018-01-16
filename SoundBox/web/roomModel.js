let resonanceAudioScene;
let soundSource;
var sourcePosition = {x: 0.25, y: 0, z: 0.25};
var elements;

//Room info
let dimensionSelection = "small";
let dimensions = {
    small: {width: 640, height: 480, depth: 640},
};

function updatePositions() {
    soundSource.setPosition(valueX, valueY, valueZ);
}

document.getElementById("playButton").onclick = function(){playMusic()};

function playMusic(){
    // Initialize Resonance Audio and create source.
    let audioContext = new AudioContext();
    //var sound2 = new Audio("music/" + )

    var e = document.getElementById("songs");
    var sound = new Audio("music/" + e.options[e.selectedIndex].value);
    console.log(e);
    console.log(e.options);
    sound.loop = true;
    sound.play();
    var source = audioContext.createMediaElementSource(sound);

    resonanceAudioScene = new ResonanceAudio(audioContext);
    //resonanceAudioScene = new ResonanceAudio(audioContext, {ambisonicOrder: 3, });
    soundSource = resonanceAudioScene.createSource();
    source.connect(soundSource.input);

    resonanceAudioScene.output.connect(audioContext.destination);
    resonanceAudioScene.setRoomProperties(dimensions[dimensionSelection]);
    
}

window.addEventListener("load", onLoad);