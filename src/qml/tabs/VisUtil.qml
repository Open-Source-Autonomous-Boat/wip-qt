import QtQuick 2.12
import QtQml 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import Qt.labs.platform 1.1
import osab.xyz.DashBoard 1.0
import osab.xyz.QtVIS 1.0

import "../snippets"
import "../settings"

ColumnLayout {
  id: root
  width: parent.width
  height: parent.height
  HeaderSnip{label_name: "VIS Editor"}
  Settings {
    id: sett
  }
  RowLayout {
    Layout.leftMargin: 20
    Layout.rightMargin: 20
    TextField {
      Layout.fillWidth: true
      height: 25
      id: file_label
      readOnly: true
      placeholderText: "Open File"
    }
    FileDialog {
      id: file_diag
      title: "Open VIS file"
      fileMode: FileDialog.OpenFile
      onAccepted: {
        QtVIS.chosen_file = file_diag.file
        file_label.text = QtVIS.UrlToFilenameWrapper(file_diag.file)
      }
    }
  }
  RowLayout {
    Layout.leftMargin: 20
    Layout.rightMargin: 20
    Button {
      text: "Open File"
      onClicked: file_diag.open()
    }
    Button {
      text: "Close File"
      onClicked: {
        file_label.text = ""
        QtVIS.chosen_file = ""
      }
    }
    Button {
      text: "Save"
    }
    Button {
      text: "Syntax"
    }
  }
  /*
   * Since colors are annyoing
   * Imma just implement a hardcoded colorscheme
   * Sucks, but should work
   * TODO: Create autothemer based on current scheme
   */
  ColumnLayout {
    Layout.leftMargin: 20
    Layout.rightMargin: 20
    Layout.bottomMargin: 5
    //visible: (file_label.text == "") ? false : true
    Rectangle {
      id: editor_area
      Layout.fillHeight: true // More of a hack but it works :)
      Layout.fillWidth: true
      color: "white"
      property int file_lines: LineNumHandle.CalculateFileLines(QtVIS.chosen_file)
      property real numbers_margin: LineNumHandle.CalculateLineWidth(file_lines)
      Flickable {
        id: editor_scroll
        anchors.fill: parent
        clip: true
        contentWidth: editor.paintedWidth
        contentHeight: editor.paintedHeight

        /* Functions */
        function scrollEnsure(el) {
          if (contentX >= el.x) {
            contentX = el.x
          } else if (contentX+width <= el.x+el.width) {
            contentX = el.x + el.width
          } if (contentY >= el.y) {
            contentY = el.y
          } else if (contentY+height <= el.y+el.height) {
            contentY = el.y + el.height
          }
        }
        TextEdit {
          id: editor
          text: QtVIS.file_contents
          color: "black"
          leftPadding: 0 //editor_area.numbers_margin + 1
          selectByMouse: true
          focus: true
          wrapMode: TextEdit.Wrap
          width: editor_scroll.width
          onCursorRectangleChanged: editor_scroll.scrollEnsure(cursorRectangle)
        }
         ScrollBar.vertical: ScrollBar { 
		   policy: ScrollBar.AlwaysOn
		}
      }
    }
  }
}
