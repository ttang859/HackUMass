const { createServer } = require("node:http");
const fs = require("node:fs");
const StringDecoder = require("node:string_decoder").StringDecoder;
const { SerialPort } = require("serialport");

const hostname = "127.0.0.1";
const server_port = 3000;

let port = new SerialPort(
  { path: "\\\\.\\COM4", baudRate: 9600 },
  function (err) {
    if (err) {
      return console.log("Error: ", err.message);
    }
  }
);

port.on("open", () => {
  console.log("port opened");
});

const frontend = fs.readFileSync("index.html", "utf-8");

const server = createServer((req, res) => {
  let buffer = "";
  let decoder = new StringDecoder("utf-8");

  req.on("data", (data) => {
    buffer += decoder.write(data);
    console.log(buffer)
    // const parsed = JSON.parse(buffer);
    // console.log(parsed["spiceSelect"]);
    port.write(buffer);
  });

  res.statusCode = 200;
  res.setHeader("Content-Type", "text/html");
  res.end(frontend);
});

server.listen(server_port, hostname, () => {
  console.log(`Server running at http://${hostname}:${server_port}/`);
});