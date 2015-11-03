import microbit as m

faces = [m.Image.CONFUSED, m.Image.HAPPY, m.Image.ANGRY, m.Image.HEART]

class MyClass(object):
    def button_monitor(self):
        while True:
            a = 2 if m.button_a.is_pressed() else 0
            b = 1 if m.button_b.is_pressed() else 0
            m.display.print(faces[a + b])
            m.sleep(100)

MyClass().button_monitor()
