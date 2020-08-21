# Healthy Programmer #

# Programmer Will Drink Water After Every 30 Minutes.
# He Will Do Eyes Exercise After Every 40 Minutes.
# And Also He Will Do Physical Exercise After Every 50 Minutes.

from pygame import mixer
import  time


def music(file, stopper):
    mixer.init()
    mixer.music.load(file)
    mixer.music.play()

    while True:
        userinput = input(f"Enter '{stopper}' To Stop {file}\n")
        if userinput == stopper:
            mixer.music.stop()
            break


def log(msg):
    with open("Logs.txt","a") as f:
        f.write(f"{msg} On {time.asctime(time.localtime(time.time()))}\n")


if __name__ == '__main__':
    initial_time_for_water = time.time()  # Initial Time For Water
    initial_time_for_eyes = time.time() # Initial Time For Eyes
    initial_time_for_exercise = time.time() # Initial Time For Exercise

    water_secs = 30*60
    eyes_secs = 40*60
    exercise_secs = 50*60


    while True:
        if time.time() - initial_time_for_water > water_secs:
            print("It's Time To Drink Water")
            music("Water.mp3","Drank")
            log("Drank Water")
            initial_time_for_water = time.time()

        if time.time() - initial_time_for_eyes > eyes_secs:
            print("It's Time To Eye Exercise")
            music("EyeExercise.mp3","Done_Eyes_Exercise")
            log("Done Eyes Exercise")
            initial_time_for_eyes = time.time()

        if time.time() - initial_time_for_exercise > exercise_secs:
            print("It's Time To Physical Exercise")
            music("PhysicalExercise.mp3","Done_Physical_Exercise")
            log("Done Physical Exercise")
            initial_time_for_exercise = time.time()
