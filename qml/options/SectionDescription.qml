import QtQuick 2.0
import VPlayApps 1.0

Rectangle {
  color: Theme.secondaryBackgroundColor
  width: parent.width
  height: appText.height + 2 * dp(Theme.navigationBar.defaultBarItemPadding)

  property alias text: appText.text

  AppText {
    id: appText
    width: parent.width - 2 * dp(Theme.navigationBar.defaultBarItemPadding)
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
    horizontalAlignment: Text.AlignHCenter
    color: Theme.secondaryTextColor
    font.pixelSize: sp(12)
  }
}
