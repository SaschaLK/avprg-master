var valueX = 0;
var valueY = 0;
var valueZ = 0;

function initialize(){
    var stateInfo = 0;

    let midi = null;  // global MIDIAccess object
    let midiInputs = [];
    function onMIDISuccess( midiAccess ) {
        console.log( "MIDI ready!" );
        midi = midiAccess;  // store in the global (in real usage, would probably keep in an object instance)
        listInputsAndOutputs(midi);
    }


    function onMIDIFailure(msg) {
        console.log( "Failed to get MIDI access - " + msg );
    }

    navigator.requestMIDIAccess({sysex:true}).then( onMIDISuccess, onMIDIFailure );
    function listInputsAndOutputs( midiAccess ) {
        const inputPortSelector = document.getElementById('inputportselector');
        for (let input of midiAccess.inputs.values()) {
            var opt = document.createElement("option");
            opt.text = input.name;
            document.getElementById("inputportselector").add(opt);
            midiInputs.push(input);
            console.log( "Input port [type:'" + input.type + "'] id:'" + input.id +
                        "' manufacturer:'" + input.manufacturer + "' name:'" + input.name +
                        "' version:'" + input.version + "'" );
        }
        if (midiInputs.length > 1){
            inputPortSelector.addEventListener('click', ()=>{
                selectMidiInput(inputPortSelector.selectedIndex);
            });
        }
        selectMidiInput(inputPortSelector.selectedIndex);
    }


    function selectMidiInput(index){
        const selectedIndex = document.getElementById('inputportselector').selectedIndex;
        const midiInput = midiInputs[selectedIndex];
        midiInput.onmidimessage = MIDIMessageEventHandler;
        return midiInput;
    }

    function MIDIMessageEventHandler(event) {
        // Check for event case (0xf0 = sysex)
        //console.log(event.data[0]);
        //calculate data value
        var value = 0;
        for(var i = 1; i < 7; i++){
            value += event.data[i];
        }
        //switch case for coordinates
        switch(stateInfo){
            case 0:
                console.log(value + " X");
                valueX = (value-320)/100;
                //updatePositions(0);
                break;
            case 1:
                console.log(value + " Y");
                valueY = (value-240)/100;
                //updatePositions(1);
                break;
            case 2:
                console.log(value + " Z");
                valueZ = (value-320)/100;
                //updatePositions(2);
        }
        stateInfo++;
        if(stateInfo == 3){
            stateInfo = 0;
            updatePositions();
        }
    }
}