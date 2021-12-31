//Start
alert("Let the game begin!")

//Game
var context, controller, player, platform, loop;

//canvas
context = document.querySelector("canvas").getContext("2d");

context.canvas.height = 180;
context.canvas.width = 320;

//Play:
var play = false;

//finish
var finishd = document.getElementById('finish');

//level
var level = 0;
var changeLevel=false;

function Play() {
	play = true;
}

player = {
	x: 144, // center of the canvas
	y: 0,
	width: 10,
	height: 10,
	x_velocity: 0,
	y_velocity: 0,
	color: "#ff5000",
	jumping: true,
	gravity: 10,
	stop: [0,0,0,0]
};

platform = {
	x: [-200,150,50,250,20],
	y: [160,120,80,50,120],
	width: [1000,100,200,50,50],
	height: [4,5,5,2,100],
	type: [1,0,0,0,1],
	color: ["#202830","#202830","#202830","#202830","lightblue"]
};

enemy = {
	x: [100,50],
	y: [145,50],
	width: [100,100],
	height: [5,5],
	x_velocity: [0,0],
	y_velocity: [0,0],
	color: "red"
};

finish = {
	x: 300,
	y: 150,
	width: 5,
	height: 5,
	color: "grey"
};

controller = {
	left: false,
	right: false,
	up: false,
	down: false,
	keyListener: function (event) {

		var key_state = (event.type == "keydown") ? true : false;

		switch (event.keyCode) {

			case 32:// space
				if (player.stop[0]==0) controller.up = key_state;
				break;
			case 37:// left key
				if (player.stop[1]==0) controller.left = key_state,player.stop[2]=0;
				break;
			case 39:// right key
				if (player.stop[2]==0) controller.right = key_state,player.stop[1]=0;
				break;
			case 40://down key
				if (player.stop[3]==0) controller.down = key_state;
				break;

		}

	}

};

loop = function () {

	if (play == true) {
		if (controller.up && player.jumping == false) {
			player.y_velocity -= 10;
			player.jumping = true;
		}

		if (controller.left) {
			player.x_velocity -= 0.5;
		}

		if (controller.right) {
			player.x_velocity += 0.5;
		}

		player.y_velocity += .3;// gravity
		player.x += player.x_velocity;
		player.y += player.y_velocity;
		player.x_velocity *= 0.9;// friction
		player.y_velocity *= 0.9;// friction

		// if rectangle is falling below floor line
		if (player.y > context.canvas.height-player.height) {
			player.jumping = false;
			player.y = context.canvas.height-player.height;
			player.y_velocity = 0;
			player.stop[0]=0;
		}

		if (player.x < -150) {// if rectangle is going off the left of the screen
			player.x = 320;
		} 
		else if (player.x > 600) {// if rectangle goes past right boundary
			player.x = -32;
		}
	}

	function collide(A1,A2,A3){
	let b1=A2.x>=A3.x[i]-A2.x&&A2.x<=A3.x[i]+A3.width[i];
	let b2=A2.x<=A3.x[i];
	let b3=A2.x>=A3.x[i]+A3.width[i];
	//_____
	let b4=A2.y>=A3.y[i]-A2.y&&A2.y<=A3.y[i]+A3.height[i];
	let b5=A2.y<=A3.y[i];
	let b6=A2.y>=A3.y[i]+A3.height[i];
	if(A1=="any")return b1&&b4&&b2||b3||b5||b6;
	else if(A1=="left")return b1&&b2;
	else if(A1=="right")return b1&&b3;
	else if(A1=="up")return b4&&b5;
	else if(A1=="down")return b4&&b6;
	};

for (i=0;i<platform.x.length;i++){
if (platform.type[i]==0 && !controller.down && collide("any",player,platform)) {
	if (!controller.up) {
				player.jumping = false;
		player.y=platform.y[i]-player.height;
				player.y_velocity = 0;
		}
		if (controller.up && player.jumping == false) {
				player.y_velocity -= player.gravity;
				player.jumping = true;
		}
} 
else if (platform.type[i]==1){
if (collide("left",player,platform)) player.x=platform.x[i]-player.width,player.stop[2]=1,controller.right=false;
else if (collide("right",player,platform)) player.x=platform.x[i]+platform.width[i],player.stop[1]=1,controller.left=false;
else if (collide("up",player,platform)) player.y_velocity=0,player.y=platform.y[i]-player.height,player.jumping=false,player.stop[0]=player.stop[1]=player.stop[2]=0;
else if (!collide("down",player,platform)) player.y_velocity+=player.gravity/2,player.jumping=true;
}
}
//for (i=0;i<enemy.x.length;i++) if (collide("any",player,enemy)) player.y=player.y_velocity = 0,player.jumping=false;
if (collide("any",player,finish) && changeLevel==false) finishd.style.color = 'lawngreen', finishd.style.textShadow = '0 0 10px lawngreen', level++, changeLevel=true;
else if (!collide("any",player,finish)) finishd.style.color = 'white', finishd.style.textShadow = '';

//levels
if (level==1 && changeLevel==true) {
player.x=0;
platform.x=[50],platform.y=[130],platform.width=[100],platform.height=[20],platform.type=[1];
changeLevel=false;
}
else if (level==2 && changeLevel==true) {
player.x=0;
platform.x=[100],platform.y=[150],platform.width=[100],platform.height=[100],platform.type=[1];
changeLevel=false;
}

	//background
	context.fillStyle = "#202020";
	context.fillRect(0, 0, 320, 180);// x, y, width, height
	//player
	if (play == true) {
		context.fillStyle = player.color;
		context.fillRect(player.x, player.y, player.width, player.height);
	}
	//platform
	for (i=0;i<platform.x.length;i++) context.fillStyle = platform.color[i],context.fillRect(platform.x[i], platform.y[i], platform.width[i], platform.height[i]);
	//enemy
	context.fillStyle = enemy.color;
	for (i=0;i<enemy.x.length;i++) context.fillRect(enemy.x[i], enemy.y[i], enemy.width[i], enemy.height[i]);
	//finish
	context.fillStyle=finish.color;
	context.fillRect(finish.x,finish.y,finish.width,finish.height);
	//level
	if (collide(0,player,finish)) context.fillStyle="lawngreen";
	else context.fillStyle="white";
	context.font = "10px Arial";
	context.fillText("Level: " + level, context.canvas.width-context.canvas.width+10, context.canvas.height-context.canvas.height+10);

	// call update when the browser is ready to draw again
	window.requestAnimationFrame(loop);

};
window.addEventListener("keydown", controller.keyListener)
window.addEventListener("keyup", controller.keyListener);
window.requestAnimationFrame(loop);