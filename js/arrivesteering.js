class Player {
    constructor(fx, fy, frad, sword) { // color
        this.fx = fx;
        this.fy = fy;
        this.frad = frad;
        this.v_velocity = [0, 0];
        this.v_accel = [0, 0];
        this.fspeed = 2.5;
        this.fpresision = 150.0;
    }
    move(p) { // [0] == mpx [1] == mpy
        let force = [];
        force.push((p[0] - this.frad * 0.75) - this.fx);
        force.push((p[1] - this.frad * 0.75) - this.fy);
        let distance = Math.sqrt(Math.pow(force[0], 2) + Math.pow(force[1], 2));
        let fcurrspeed = this.fspeed;
        if (distance < this.fpresision)
            fcurrspeed = map(distance, 0, this.fpresision, 0, fcurrspeed);
        let mag = Math.sqrt(Math.pow(force[0], 2)  + Math.pow(force[1], 2));
        if (0 != mag && 1 != mag) {
            force[0] = force[0] / mag;
            force[1] = force[1] / mag;
        }
        force[0] *= fcurrspeed;
        force[1] *= fcurrspeed;
        force[0] -= this.v_velocity[0];
        force[1] -= this.v_velocity[1];
        this.v_accel[0] += force[0];
        this.v_accel[1] += force[1];
        this.v_velocity[0] += this.v_accel[0];
        this.v_velocity[1] += this.v_accel[1];
        this.fx += this.v_velocity[0];
        this.fy += this.v_velocity[1];
        this.v_accel = [0, 0];
    }
    display() {
        var canvas = document.getElementById("canvas");
        var context = canvas.getContext("2d");
        context.beginPath();
        context.arc(this.fx, this.fy, this.frad, 0, 2 * Math.PI);
        context.stroke();
        context.closePath();
    }
}

let player = new Player(0, 0, 50);
var coords = [0.0, 0.0];

onload = () => {
    setInterval(updatePlayer, 1000/60);
    setup();
}

function setup() {
    let sPage = "";
    sPage += "<canvas id='canvas' width='1500' height='800' style='border: 1px solid #000000;' onmousemove='updateCoords()'></canvas>";
    document.getElementById('Main').innerHTML = sPage;
}

function updateCoords() {
    coords[0] = event.clientX;
    coords[1] = event.clientY;
}

function updatePlayer() {
    var canvas = document.getElementById("canvas");
    var context = canvas.getContext("2d");
    context.clearRect(0, 0, 1500, 800);

    player.move(coords);
    player.display();
}

function map(num, min1, max1, min2, max2) {
    return min2 + (max2 - min2) * ((num - min1) / (max1 - min1));
}
