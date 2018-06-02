const express = require("express");
const expressApp = express();
const http = require("http").Server(expressApp);
const io = require("socket.io")(http);
const { app, BrowserWindow } = require("electron");
const { spawn, exec } = require("child_process");
const backend = spawn("./backend/cmake-build-debug/backend");

backend.stdout.on("error", data => {
  console.log(`error: ${data}`);
});

backend.stdout.on("data", data => {
  try {
    const json = JSON.parse(data.toString());
    io.emit("data", json);
  } catch (e) {
    //
  }
});

const port = process.env.PORT || 3000;

expressApp.use(express.static(__dirname + "/frontend/public"));

expressApp.get("/", (req, res) =>
  res.sendFile(__dirname + "/frontend/public/index.html")
);

function onConnection(socket) {
  socket.on("disconnect", function() {
    console.log("user disconnected");
  });
}

io.on("connection", onConnection);

http.listen(port, () => console.log("listening on port " + port));

function createWindow() {
  // Create the browser window.
  const win = new BrowserWindow({ width: 1300, height: 800 });

  // and load the index.html of the app.
  win.loadURL("http://localhost:3000/");
}

app.on("ready", createWindow);
