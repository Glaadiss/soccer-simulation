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
  // writePitch();
  for (let i = 0; i < 11; i++) {
    const { x, y } = json[i + 1];
    writePlayer(x * scaleX, y * scaleY, "red", i + 1);
  }
  for (let i = 0; i < 11; i++) {
    const { x, y } = json[i + 12];
    writePlayer(x * scaleX, y * scaleY, "blue", i + 1);
  }
  const { x, y } = json[23];
  writeBall(x * scaleX, y * scaleY);
}

function eraseField() {
  ctx.clearRect(0, 0, width, height);
}

function writeBall(x, y) {
  ctx.beginPath();
  ctx.strokeStyle = "#33aa33";
  ctx.fillStyle = "white";
  ctx.arc(x, y, 5, 0, 2 * Math.PI);
  ctx.fill();
  ctx.closePath();
}

function randomizeLocation() {
  return [Math.random() * 1500 + 50, Math.random() * 800 + 50];
}
function writePlayer(x, y, fill, id) {
  ctx.fillStyle = fill;
  ctx.beginPath();
  ctx.arc(x, y, 10, 0, 2 * Math.PI);
  ctx.fill();
  ctx.font = "12px Arial";
  ctx.fillStyle = "yellow";
  ctx.fillText(
    `${id}:(${Math.round(x / scaleX)}, ${Math.round(y / scaleY)})`,
    x,
    y
  );

  ctx.closePath();
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
  ctx.beginPath();
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
  ctx.closePath();
}

function writeLine(srcX, srcY, destX, destY) {
  ctx.moveTo(srcX, srcY);
  ctx.lineTo(destX, destY);
  ctx.stroke();
}
