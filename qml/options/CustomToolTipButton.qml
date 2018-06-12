import QtQuick 2.0
import QtQuick.Controls 2.0
import VPlayApps 1.0

AppButton {
  property string toolTip

  ToolTip.visible: pressed
  ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
  ToolTip.text: toolTip
  verticalMargin: 0
}
