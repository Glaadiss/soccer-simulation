const express = require("express");
const app = express();
const http = require("http").Server(app);
const io = require("socket.io")(http);
const { spawn, exec } = require("child_process");
const backend = spawn("./../backend/cmake-build-debug/backend");

backend.stdout.on("error", data => {
  console.log(`error: ${data}`);
});

backend.stdout.on("data", data => {
  const json = JSON.parse(data);
  io.emit("data", json);
});

const port = process.env.PORT || 3000;

app.use(express.static(__dirname + "/public"));

app.get("/", (req, res) => res.sendFile(__dirname + "/public/index.html"));

function onConnection(socket) {
  // socket.on('drawing', (data) => socket.broadcast.emit('drawing', data));
  console.log("a user connected");
  socket.on("disconnect", function() {
    console.log("user disconnected");
  });
}

// setInterval(() => {
//   io.emit("event", { event: "something event" });
// }, 500);

io.on("connection", onConnection);

http.listen(port, () => console.log("listening on port " + port));
