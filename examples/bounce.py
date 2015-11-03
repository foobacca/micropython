import microbit as m

paddle_position = 0

ball_position = [m.random(5), 0]

if ball_position[0] == 4:
    ball_going_right = False
elif ball_position[0] == 0:
    ball_going_right = True
else:
    ball_going_right = bool(m.random(2))

ball_going_down = True


def update_ball_left_right():
    global ball_going_right
    if ball_going_right:
        ball_position[0] += 1
    else:
        ball_position[0] -= 1
    if ball_position[0] == 0:
        ball_going_right = True
    if ball_position[0] == 4:
        ball_going_right = False


def update_ball_up_down():
    global ball_going_down
    if ball_going_down:
        ball_position[1] += 1
    else:
        ball_position[1] -= 1
    if ball_position[1] == 0:
        ball_going_down = True
    if ball_position[1] == 4:
        ball_going_down = False


def show_ball():
    m.display.clear()
    m.display.set_pixel(ball_position[0], ball_position[1], 9)


def update_bat():
    pass


def main():
    while True:
        update_ball_left_right()
        update_ball_up_down()
        show_ball()
        m.sleep(200)

main()
