import easygui
import sys

while 1:
    easygui.msgbox("Hello, world!")

    msg ="What is your favorite flavor?"
    title = "Ice Cream Survey"
    choices = ["Vanilla", "Chocolate", "Strawberry", "Rocky Road"]
    choice = easygui.choicebox(msg, title, choices)

    # note that we convert choice to string, in case
    # the user cancelled the choice, and we got None.
    easygui.msgbox("You chose: " + str(choice), "Survey Result")

    msg = "Do you want to continue?"
    title = "Please Confirm"
    if easygui.ccbox(msg, title):     # show a Continue/Cancel dialog
        pass  # user chose Continue
    else:
        sys.exit(0)           # user chose Cancel
