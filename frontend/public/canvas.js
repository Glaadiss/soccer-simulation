var socket = io();
socket.on("data", function(json) {
  eraseField();
  writeGame(json);
});

const c = document.getElementById("myCanvas");
const ctx = c.getContext("2d");
const width = c.clientWidth;
const scaleX = width / 100;
const height = c.clientHeight;
const scaleY = height / 100;
ctx.lineWidth = 2;

// writeGame();

function writeGame(json) {
  writePitch();
  for (let i = 0; i < 11; i++) {
    const { x, y } = json[i + 1];
    writePlayer(x * scaleX, y * scaleY, "red");
  }
  for (let i = 0; i < 11; i++) {
    const { x, y } = json[i + 11];
    writePlayer(x * scaleX, y * scaleY, "blue");
  }
  const { x, y } = json[23];
  writeBall(x * scaleX, y * scaleY);
}

function eraseField() {
  ctx.clearRect(0, 0, width, height);
}

function writeBall(x, y) {
  ctx.fillStyle = "white";
  ctx.beginPath();
  ctx.arc(x, y, 10, 0, 2 * Math.PI);
  ctx.fill();
}

function randomizeLocation() {
  return [Math.random() * 1500 + 50, Math.random() * 800 + 50];
}
function writePlayer(x, y, fill) {
  ctx.strokeStyle = "red";
  ctx.fillStyle = fill;
  ctx.beginPath();
  ctx.arc(x, y, 20, 0, 2 * Math.PI);
  ctx.fill();
  // ctx.strokeStyle = "yellow";
  // const sightRadius = 40;
  // const angle = Math.random() * 360;
  // const secondAngle = angle > 180 ? angle - 20 : angle + 20;
  // firstX = Math.cos(angle) * sightRadius + x;
  // firstY = Math.sin(angle) * sightRadius + y;
  // secondX = Math.cos(secondAngle) * sightRadius + x;
  // secondY = Math.sin(secondAngle) * sightRadius + y;
  // writeLine(x, y, firstX, firstY);
  // writeLine(x, y, secondX, secondY);
  // writeLine(firstX, firstY, secondX, secondY);
}

const angle = Math.random() * 360;
const secondAngle = angle > 180 ? angle - 60 : angle + 60;

function writePitch() {
  ctx.strokeStyle = "white";
  writeLine(width / 2, 0, width / 2, height);

  writeLine(0, 0.2 * height, 0.2 * width, 0.2 * height);
  writeLine(0.2 * width, 0.2 * height, 0.2 * width, height - 0.2 * height);
  writeLine(0.2 * width, height - 0.2 * height, 0, height - 0.2 * height);

  writeLine(width, 0.2 * height, width - 0.2 * width, 0.2 * height);
  writeLine(
    width - 0.2 * width,
    0.2 * height,
    width - 0.2 * width,
    height - 0.2 * height
  );
  writeLine(
    width - 0.2 * width,
    height - 0.2 * height,
    width,
    height - 0.2 * height
  );
}

function writeLine(srcX, srcY, destX, destY) {
  ctx.moveTo(srcX, srcY);
  ctx.lineTo(destX, destY);
  ctx.stroke();
}
