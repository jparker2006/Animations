class Pedulum {
    constructor(vorigin, flen) {
        this.vpos = [0, 0];
        this.vorigin = vorigin;
        this.flen = flen;
        this.theta = Math.PI / 4;
        this.theta_vel = 0;
        this.theta_acc = 0;
        this.fdamp = 0.995;
        this.fgrav = 0.4;
    }
    applyforce() {
        this.theta_acc = (-1 * this.fgrav / this.flen) * Math.sin(this.theta);
        this.theta_vel += this.theta_acc;
        this.theta_vel *= this.fdamp;
        this.theta += this.theta_vel;
    }
    display() {
        let canvas = document.getElementById("canvas");
        let context = canvas.getContext("2d");
        this.vpos = [this.calc_polar_coords(true) + this.vorigin[0], this.calc_polar_coords(false) + this.vorigin[1]];
        context.beginPath();
        context.arc(this.vpos[0], this.vpos[1], 12, 0, 2 * Math.PI);
        context.fill();
        context.closePath();
        context.beginPath();
        context.moveTo(this.vorigin[0], this.vorigin[1]);
        context.lineTo(this.vpos[0], this.vpos[1]);
        context.stroke();
    }
    calc_polar_coords(bsin) {
        if (bsin)
            return Math.sin(this.theta) * this.flen;
        return Math.cos(this.theta) * this.flen;
    }
}

onload = () => {
    MainFrame();
}

var p = [];
function MainFrame() {
    let sPage = "";
    sPage += "<canvas id='canvas' width='1200px' height='600px' style='background-color: lightblue;'></canvas>";
    document.getElementById('Main').innerHTML = sPage;
    setInterval(paint, 1000/60);
    for (let i=100; i<500; i+=50) {
        p.push(new Pedulum([600, 0], i));
    }
}

function paint() {
    let canvas = document.getElementById("canvas");
    let context = canvas.getContext("2d");
    context.clearRect(0, 0, canvas.width, canvas.height);
    for (let i=0; i<p.length; i++) {
        p[i].applyforce();
        p[i].display();
    }
}
