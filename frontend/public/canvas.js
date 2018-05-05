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

function writeGame(json) {
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
  const {scores: {red, blue}} = json;
  writeScores(red, blue);
}

function eraseField() {
  ctx.clearRect(0, 0, width, height);
}

function writeScores(red, blue){
  ctx.font = "30px Comic Sans MS";
  ctx.fillStyle = "yellow";
  ctx.textAlign = "center";
  ctx.fillText(`Red ${red} : ${blue} Blue`, width/2, 40);
}
function writeBall(x, y) {
  ctx.beginPath();
  ctx.strokeStyle = "#33aa33";
  ctx.fillStyle = "white";
  ctx.arc(x, y, 5, 0, 2 * Math.PI);
  ctx.fill();
  ctx.closePath();
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
}
