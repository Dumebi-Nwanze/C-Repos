import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Todo App")

    ListModel{
        id:todoModel
    }

    Item{
        anchors.fill: parent

        Rectangle{
            id: appBar
            height: 100
            width: parent.width
            color: "blue"
            anchors.top: parent.top

            Text{
                text: "My Todos"
                color: "white"
                font.bold: true
                font.pixelSize: 32
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 35
            }
        }

        Item{
            width: parent.width
            anchors.bottom: parent.bottom
            anchors.top: appBar.bottom

            Rectangle{
                id: displayPanel
                width: parent.width / 2
                height: parent.height
                anchors.left: parent.left
                color: "#c4c4c4"

                ListView{
                    id: todoLists
                    model: todoModel
                    spacing: 5
                    anchors.centerIn: parent
                    width: parent.width * 0.7
                    height: parent.height * 0.8
                    delegate: Rectangle{
                        id: todoItem
                        width: todoLists.width
                        height: 50
                        color: "white"
                        radius: 10

                        property string title
                        property string desc

                        title: _title
                        desc: _desc
                        Rectangle{
                            id: deleteBtn
                            color: "red"
                            width: 50
                            radius: 10
                            height: parent.height /2
                            anchors.right: parent.right
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.rightMargin: 5
                            Text{
                                anchors.centerIn: parent
                                color: "White"
                                font.pixelSize: 12
                                text: "Delete"
                            }
                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    todoModel.remove(index)
                                }
                            }
                        }


                        Column{
                            anchors.fill: parent

                            anchors.leftMargin: 20
                            anchors.rightMargin: 10
                            anchors.topMargin: 5
                            anchors.bottomMargin: 5

                            Text{
                                color: "Black"
                                font.bold: true
                                font.pixelSize: 18
                                text: todoItem.title
                            }

                            Text{
                                color: "Black"
                                font.pixelSize: 16
                                text: todoItem.desc
                            }

                        }


                    }
                }
            }

            Item{
                id:inputPanel
                width: parent.width / 2
                height: parent.height
                anchors.right: parent.right

                Column{
                    anchors.top:parent.top
                    anchors.topMargin: 5
                    spacing: 10
                    anchors.horizontalCenter: parent.horizontalCenter

                    TextField{
                        id: titleTextArea
                        placeholderText: "Enter Title"
                        height: inputPanel.height * 1/7
                        width: inputPanel.width * 0.7
                        color: "black"

                    }

                    TextArea{
                        id: descTextArea
                        placeholderText: "Enter Todo Description"
                        width: inputPanel.width * 0.7
                        height: inputPanel.height * 3/5
                    }

                    Button{

                        text: "Add Todo"
                        height: inputPanel.height * 1/7
                        width: inputPanel.width*0.7
                        onClicked: {
                            if(titleTextArea.text!=""&&descTextArea.text!=""){
                                todoModel.append({

                                                 "_title":titleTextArea.text,"_desc":descTextArea.text})
                                descTextArea.text = ""
                                titleTextArea.text = ""
                            }


                        }
                    }
                }
            }
        }
    }
}
