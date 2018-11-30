# -*- coding: utf-8 -*-




import turtle
import os
import time 
import math
import random
import pygame
pygame.init()
s = pygame.mixer.Sound("laser.wav")
ns = pygame.mixer.music.load("sound1.wav")
pygame.mixer.music.play()
window=turtle.Screen()
window.bgcolor("black")
window.title("Alien Game")
window.bgpic("spaceback.png")
#border
turtle.register_shape("ship1.gif")
turtle.register_shape("alien.gif")

border_p=turtle.Turtle()
border_p.speed(0)
border_p.color("white")
border_p.penup()

border_p.setposition(-400,-300)
border_p.pendown()
border_p.pensize(3)


border_p.hideturtle()    


player=turtle.Turtle()
player.shape("ship1.gif")
player.penup()
player.speed(0)
player.setposition(0,-250)
player.setheading(90)

playerspeed=20
number_of_enemies=5
enemies =[]
for i in range(number_of_enemies):
    enemies.append(turtle.Turtle())
for enemy in enemies:
    enemy.color("red")
    enemy.shape("alien.gif")
    enemy.penup()
    enemy.speed(0)
    x=random.randint(-200,200)
    y=random.randint(100,250)
    enemy.setposition(x,y)

enemyspeed =6
bullet=turtle.Turtle()
bullet.color("yellow")
bullet.shape("circle")
bullet.penup()
bullet.speed(0)
bullet.shapesize(0.2,0.2)
bullet.hideturtle()
bulletspeed =30
bulletstate =True







score=0
sc=turtle.Turtle()
sc.speed(0)
sc.color("white")
sc.penup()
sc.setposition(-400,280)
scstr="Score: %s"%score
sc.write(scstr,False,align="left",font=("Arial",16,"normal"));
sc.hideturtle()
def fire_bullet():
    global bulletstate
    if bulletstate==True:
        s.play()
        x=player.xcor()
        y=player.ycor()+10
        bullet.setposition(x,y)
        bullet.showturtle()
        bulletstate=False
        #s.stop()
        
    
def move_left():
    x=player.xcor()
    x-=playerspeed
    if x<-340:
        x=-340
    player.setx(x)
    
def isCollision(t1,t2):
    distance=math.sqrt(math.pow(t1.xcor()-t2.xcor(),2)+math.pow(t1.ycor()-t2.ycor(),2))    
    if distance< 35:
        return True
    else:
        return False
def move_right():
    x=player.xcor()
    x+=playerspeed
    if x>340:
        x=340
    player.setx(x)
    
turtle.listen()
turtle.onkey(move_right,"Right")    
turtle.listen()
turtle.onkey(move_left,"Left")  
turtle.onkey(fire_bullet,"space") 
while True:
    for enemy in enemies:
        x=enemy.xcor()
        x+=enemyspeed
        enemy.setx(x)
        if enemy.xcor()>290:
            for e in enemies:
                y=e.ycor()
                y-=40;
                e.sety(y)
            enemyspeed *=-1
        if enemy.xcor()<-290:
            for e in enemies:
                y=e.ycor()
                y-=40;
                e.sety(y)
            enemyspeed *=-1
        if isCollision(bullet,enemy):
            bullet.hideturtle()
            bulletstate=True
            bullet.setposition(0,-400)
            enemy.setposition(-200,250)
            score+=10
            scstr="Score: %s"%score
            sc.clear()
            sc.write(scstr,False,align="left",font=("Arial",16,"normal"));
            sc.hideturtle()
        if isCollision(player,enemy):
            player.hideturtle()
            enemy.hideturtle()
            tc=turtle.Turtle()
            tc.speed(0)
            tc.color("red")
            tc.penup()
            tc.setposition(10,-50)
            tcstr="GAME OVER"
            tc.write(tcstr,False,align="left",font=("Arial",25,"normal"));
            tc.bye()
        if enemy == 5:
            pygame.mixer.music.play()
    if bulletstate ==False:    
        y=bullet.ycor()
        y+=bulletspeed
        bullet.sety(y)
    if bullet.ycor()>275:
        bullet.hideturtle()
        bulletstate=True

turtle.mainloop()
