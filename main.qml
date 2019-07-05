import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.10



Window {
    visible: true
    width: 640
    height: 480
    color: "#303f9f"
    title: qsTr("Anagram​ ​ derivation")
    signal submitTextField(string text)
    signal submitFile(string text)

    Rectangle
    {
                anchors.fill: parent

                gradient: Gradient{

                GradientStop {position: 0.225;color: "#330867"}
                GradientStop {
                    position: 0.229
                    color: "#330867"
                }

                GradientStop {position: 1.000;color: "#30cfd0"}


                }

            Label {
                id: label
                x: 469
                y: 215
                width: 28
                height: 17
                text: qsTr("")
                visible: false
            }

            Text {
                id: element
                x: 469
                y: 123
                width: 41
                height: 23
                color: "#ffffff"
                text: qsTr("3.")
                font.bold: true
                font.pixelSize: 16
            }
    }
    Text {
        id: mainText
        x: 153
        y: 53
        color: "#ffffff"
        text: qsTr("Anagram​ ​ derivation")
        font.italic: true
        font.bold: true
        font.family: "Courier"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 30
    }

    Text {
        id: text2
        x: 267
        y: 121
        color: "#ffffff"
        text: qsTr("2.Load Dictionary")
        textFormat: Text.PlainText
        font.bold: true
        font.weight: Font.Normal
        font.capitalization: Font.MixedCase
        font.pixelSize: 16
    }

    Button {
        x: 267
        y: 150
        text: "Load"
        wheelEnabled: false
        autoRepeat: false
        flat: false
        font.weight: Font.Medium
        focusPolicy: Qt.StrongFocus
        highlighted : true
        onClicked: openFileDialog.open()
    }
    Button {
        x: 469
        y: 150
        text: "Find"
        highlighted : true
        onClicked: {submitTextField(intputText.text), submitTextField(label.text)}

    }
    function openFile(fileUrl) {
        var request = new XMLHttpRequest();
        request.open("GET", fileUrl, false);
        request.send(null);
        return request.responseText;
    }


    function setTextField(text){
        console.log("setTextField: " + text)
        outputText.text = text
    }


    FileDialog {
        id: openFileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        nameFilters: [ "Text file (*.txt)", "All files (*)" ]

        onAccepted: {   var path = openFileDialog.fileUrl.toString();
            // remove prefixed "file:///"
            if(Qt.platform.os=="windows") {
              path = path.replace(/^(file:\/{3})/,"")
            }
            else
               path = path.replace(/^(file:\/{2})/,"")

            label.text=(path)

}
    }



    FileDialog {
        id: saveFileDialog
        selectExisting: false
        folder: shortcuts.home
        nameFilters: ["Text files (*.txt)", "All files (*)"]
        onAccepted: saveFile(saveFileDialog.fileUrl, outputText.text)
    }

    Rectangle {
        id: rectangle
        x: 38
        y: 150
        width: 85
        height: 35
        border.color: "#3232CD"
        border.width: 1
         color: "#2F2F4F"
         ScrollView {
             anchors.rightMargin: 0
             anchors.bottomMargin: 0
             anchors.leftMargin: 0
             anchors.topMargin: 0
               anchors.fill: parent
             TextArea {
            id: intputText
              anchors.fill: parent
            width: 73
            height: 20
            color: "white"
            text:""
            font.pointSize: 12
            anchors.bottomMargin: 3
            anchors.leftMargin: -4
            anchors.rightMargin: -59

        }
    }
    }



    Rectangle {
        id: rectangle1
        x: 38
        y: 215
        width: 585
        height: 187
        color: "#2F2F4F"
        border.color: "#3232CD"
        border.width: 1
        ScrollView {
            anchors.fill: parent
        TextArea {
            id: outputText
            x: 0
            y: 0
            width: 585
            height: 86
            readOnly : true
            color: "white"
            text:""
            }
        }
    }

    Text {
        id: text3
        x: 38
        y: 121
        color: "#ffffff"
        text: qsTr("1.Enter 3-letter word")
        font.capitalization: Font.MixedCase
        textFormat: Text.PlainText
        font.bold: true
        font.weight: Font.Normal
        font.pixelSize: 16
    }


    }





