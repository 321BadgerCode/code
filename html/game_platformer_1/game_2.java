//Start
alert("Let the game begin!")

//Game
var context, controller, player, platform, loop;

context = document.querySelector("canvas").getContext("2d");

context.canvas.height = 180;
context.canvas.width = 320;

var finish = document.getElementById('finish');

player = {
    height: 10,
    width: 10,
    jumping: true,
    x: 10, 
    y: 0,
    x_velocity: 0,
    y_velocity: 0,
    color: "#ff088855"
};

enemy={
    height: 10,
    width: 10,
    x: 310, 
    y: 170,
    x_velocity: 0,
    y_velocity: 0,
    color: "red"
}
dead=false;
score=0;

controller = {

    left: false,
    right: false,
    up: false,
    down: false,
    keyListener: function (event) {

        var key_state = (event.type == "keydown") ? true : false;

        switch (event.keyCode) {

            case 37:// left key
                controller.left = key_state;
                break;
            case 32:// space
                controller.up = key_state;
                break;
            case 40://down key
                controller.down = key_state;
                break;
            case 39:// right key
                controller.right = key_state;
                break;

        }

    }

};

loop = function () {

        if (controller.up && player.jumping == false) {

            player.y_velocity -= 10;
            player.jumping = true;

        }

        player.y_velocity += .3;// gravity
        player.x += player.x_velocity;
        player.y += player.y_velocity;
        player.x_velocity *= 0.9;// friction
        player.y_velocity *= 0.9;// friction

        // if rectangle is falling below floor line
        if (player.y > 180 - player.height) {

            player.jumping = false;
            player.y = 180 - player.height;
            player.y_velocity = 0;

        }

        //player
        if (player.x<=enemy.x+player.width && player.x>=enemy.x-enemy.width && player.y<=enemy.y+player.height && player.y>=enemy.y-enemy.height) dead=true; 

        //player death
        if (dead==true) alert("Dead!"),score=0,enemy.x=310,enemy.x_velocity=0,player.y=170,player.color="yellow",dead=false;
        else if (dead==false) player.color="#ff088855";

        //enemy
        enemy.x_velocity-=.01;
        enemy.x+=enemy.x_velocity;
        if (enemy.x<player.x-player.width) score++,enemy.x=310;  

    //background
    context.fillStyle = "#202020";
    context.fillRect(0, 0, 320, 180);// x, y, width, height
    //player
    context.fillStyle = player.color;// player color
    context.beginPath();
    context.rect(player.x, player.y, player.width, player.height);
    context.fill();
    //enemy
    context.fillStyle = enemy.color;
    context.beginPath();
    context.rect(enemy.x,enemy.y,enemy.width,enemy.height);
    context.fill();
    //score
    context.fillStyle="white";
    context.font = "10px Arial";
    context.fillText("Score: " + score, context.canvas.width-context.canvas.width+10, context.canvas.height-context.canvas.height+10);

    // call update when the browser is ready to draw again
    window.requestAnimationFrame(loop);

};

window.addEventListener("keydown", controller.keyListener)
window.addEventListener("keyup", controller.keyListener);
window.requestAnimationFrame(loop);
