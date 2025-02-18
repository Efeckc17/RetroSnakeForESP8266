#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "YOURSSID";
const char* password = "YOURPASSWORD";
ESP8266WebServer server(80);

String generatePage() {
  String page = R"====(
<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8">
  <title>Neon Snake</title>
  <style>
    html, body {
      margin: 0;
      padding: 0;
      width: 100%;
      height: 100%;
      background: #000;
      overflow: hidden;
    }
    #gameCanvas {
      display: block;
      width: 100%;
      height: 100%;
    }
    #score {
      position: absolute;
      top: 15px;
      left: 15px;
      color: #0f0;
      font-size: 1em;
      font-family: sans-serif;
      text-shadow: 0 0 5px #0f0, 0 0 10px #0f0;
      z-index: 2;
    }
    #gameOver {
      position: absolute;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
      background: rgba(0,0,0,0.8);
      display: none;
      justify-content: center;
      align-items: center;
      flex-direction: column;
      color: #fff;
      z-index: 3;
      text-align: center;
    }
    #gameOver button {
      margin-top: 20px;
      padding: 10px 20px;
      font-size: 1em;
      border: none;
      border-radius: 5px;
      background: #444;
      color: #fff;
      cursor: pointer;
      transition: 0.3s;
      font-family: sans-serif;
      text-shadow: 0 0 5px #fff;
    }
    #gameOver button:hover {
      background: #666;
    }
    #settingsBtn {
      position: absolute;
      top: 15px;
      right: 15px;
      z-index: 2;
      color: #fff;
      background: #444;
      padding: 5px 10px;
      border: none;
      cursor: pointer;
      border-radius: 5px;
      font-family: sans-serif;
      text-shadow: 0 0 5px #fff;
      transition: 0.3s;#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ssıd";

const char* password = "password";



String generatePage() {
…  server.begin();
}

void loop() {
  server.handleClient();
}

    }
    #settingsBtn:hover {
      background: #666;
    }
    #settingsPanel {
      position: absolute;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%);
      background: rgba(0,0,0,0.9);
      padding: 20px;
      border-radius: 10px;
      z-index: 4;
      display: none;
      flex-direction: column;
      gap: 10px;
      color: #fff;
      width: 250px;
      font-family: sans-serif;
      text-align: left;
    }
    #settingsPanel > label {
      display: flex;
      flex-direction: column;
      font-size: 0.9em;
      margin-bottom: 5px;
    }
    #settingsPanel input,
    #settingsPanel select {
      margin-top: 3px;
      padding: 5px;
      font-size: 1em;
      color: #000;
      border-radius: 3px;
    }
    #settingsPanel button {
      margin-top: 5px;
      padding: 8px 12px;
      font-size: 1em;
      cursor: pointer;
      border: none;
      border-radius: 5px;
      background: #444;
      color: #fff;
      transition: 0.3s;
      text-shadow: 0 0 5px #fff;
    }
    #settingsPanel button:hover {
      background: #666;
    }
    #status {
      position: absolute;
      bottom: 15px;
      left: 15px;
      color: #0f0;
      font-size: 0.9em;
      font-family: sans-serif;
      text-shadow: 0 0 5px #0f0;
      z-index: 2;
    }
    #deviceInfo {
      margin-top: 10px;
      padding: 10px;
      background: rgba(255,255,255,0.1);
      border-radius: 5px;
      line-height: 1.4em;
    }
    #deviceInfo ul {
      list-style: none;
      padding: 0;
      margin: 0;
    }
    #deviceInfo li {
      margin-bottom: 4px;
    }
  </style>
</head>
<body>
  <div id="score">
    SCORE: <span id="scoreVal">0</span>
  </div>
  <button id="settingsBtn">SETTINGS</button>
  <div id="settingsPanel">
    <label>
      Snake Name
      <input id="snakeName" type="text" value="Snake"/>
    </label>
    <label>
      Speed (ms per move)
      <input id="snakeSpeed" type="number" min="50" max="1000" step="10" value="200"/>
    </label>
    <label>
      Food Distance (0=any)
      <input id="foodDist" type="number" min="0" max="20" value="0"/>
    </label>
    <label>
      Snake Color
      <input id="snakeColor" type="color" value="#0ff"/>
    </label>
    <label>
      Food Color
      <input id="foodColor" type="color" value="#f0f"/>
    </label>
    <label>
      Background
      <input id="bgColor" type="color" value="#000000"/>
    </label>
    <label>
      Shape
      <select id="snakeShape">
        <option value="circle">Circle</option>
        <option value="square">Square</option>
      </select>
    </label>
    <div id="deviceInfo">
      <strong>Device Info</strong>
      <ul>
        <li>IP: <span id="ipSpan">{{IP}}</span></li>
        <li>MAC: <span id="macSpan">{{MAC}}</span></li>
        <li>Hostname: <span id="hostSpan">{{HOST}}</span></li>
        <li>RSSI: <span id="rssiSpan">{{RSSI}}</span> dBm</li>
        <li>ChipID: <span id="chipSpan">{{CHIPID}}</span></li>
        <li>Free Heap: <span id="heapSpan">{{FREEHEAP}}</span> bytes</li>
      </ul>
    </div>
    <button onclick="applySettings()">APPLY</button>
  </div>
  <div id="gameOver">
    <div style="font-size:2em;">GAME OVER!</div>
    <div style="margin-top:10px;">
      SCORE: <span id="finalScore">0</span>
    </div>
    <button onclick="restartGame()">RESTART</button>
  </div>
  <div id="status">
    Ping: <span id="pingVal">0</span> ms | FPS: <span id="fpsVal">0</span>
  </div>
  <canvas id="gameCanvas"></canvas>
  <script>
    let cv=document.getElementById("gameCanvas");
    let ctx=cv.getContext("2d");
    let scoreEl=document.getElementById("scoreVal");
    let goDiv=document.getElementById("gameOver");
    let fs=document.getElementById("finalScore");
    let settingsBtn=document.getElementById("settingsBtn");
    let settingsPanel=document.getElementById("settingsPanel");
    let snakeNameEl=document.getElementById("snakeName");
    let snakeSpeedEl=document.getElementById("snakeSpeed");
    let foodDistEl=document.getElementById("foodDist");
    let snakeColorEl=document.getElementById("snakeColor");
    let foodColorEl=document.getElementById("foodColor");
    let bgColorEl=document.getElementById("bgColor");
    let snakeShapeEl=document.getElementById("snakeShape");
    let pingVal=document.getElementById("pingVal");
    let fpsVal=document.getElementById("fpsVal");
    let w=innerWidth;
    let h=innerHeight;
    cv.width=w;
    cv.height=h;
    let box=20;
    let cols=Math.floor(w/box);
    let rows=Math.floor(h/box);
    let snake=[];
    let length=3;
    let direction="RIGHT";
    let score=0;
    let moveInterval=200;
    let lastFrame=0;
    let timeSinceMove=0;
    let isOver=false;
    let isPaused=false;
    let food={x:0,y:0};
    let snakeName="Snake";
    let snakeColor="#0ff";
    let foodColor="#f0f";
    let bgColor="#000";
    let sShape="circle";
    let fDist=0;
    let prevFrameTime=0;
    let frameCount=0;
    let fps=0;
    for(let i=0;i<length;i++){
      snake.push({x:Math.floor(cols/2)-i,y:Math.floor(rows/2)});
    }
    function spawnFood(){
      for(;;){
        food.x=Math.floor(Math.random()*(cols-2))+1;
        food.y=Math.floor(Math.random()*(rows-2))+1;
        let dist=Math.sqrt(Math.pow(food.x-snake[0].x,2)+Math.pow(food.y-snake[0].y,2));
        if(!fDist||dist>=fDist){#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "ssıd";

const char* password = "password";



String generatePage() {
…  server.begin();
}

void loop() {
  server.handleClient();
}

          break;
        }
      }
    }
    spawnFood();
    document.addEventListener("keydown",e=>{
      if(isOver)return;
      if(e.keyCode==37&&direction!="RIGHT")direction="LEFT";
      else if(e.keyCode==38&&direction!="DOWN")direction="UP";
      else if(e.keyCode==39&&direction!="LEFT")direction="RIGHT";
      else if(e.keyCode==40&&direction!="UP")direction="DOWN";
      else if(e.keyCode==32){
        isPaused=!isPaused;
      }
    });
    requestAnimationFrame(loop);
    setInterval(measurePing,2000);
    function loop(t){
      let delta=t-lastFrame;
      lastFrame=t;
      frameCount++;
      if(t-prevFrameTime>=1000){
        fps=frameCount;
        frameCount=0;
        prevFrameTime=t;
      }
      fpsVal.textContent=fps;
      if(!isPaused){
        timeSinceMove+=delta;
        if(timeSinceMove>=moveInterval){
          moveSnake();
          timeSinceMove-=moveInterval;
        }
      }
      draw();
      if(!isOver){
        requestAnimationFrame(loop);
      }
    }
    function draw(){
      ctx.fillStyle=bgColor;
      ctx.fillRect(0,0,w,h);
      for(let i=0;i<snake.length;i++){
        if(i==0){
          ctx.shadowColor="#fff";
          ctx.shadowBlur=20;
          ctx.fillStyle="#fff";
        } else {
          ctx.shadowColor=snakeColor;
          ctx.shadowBlur=15;
          ctx.fillStyle=snakeColor;
        }
        let px=snake[i].x*box;
        let py=snake[i].y*box;
        if(sShape=="circle"){
          ctx.beginPath();
          ctx.arc(px+box/2,py+box/2,box/2,0,2*Math.PI);
          ctx.fill();
        } else {
          ctx.fillRect(px,py,box,box);
        }
        if(i==0){
          ctx.fillStyle="#fff";
          ctx.font=(box*0.7)+"px sans-serif";
          ctx.textAlign="center";
          ctx.textBaseline="middle";
          ctx.shadowBlur=10;
          ctx.fillText(snakeName,px+box/2,py+box/2);
        }
      }
      ctx.shadowColor=foodColor;
      ctx.shadowBlur=15;
      ctx.fillStyle=foodColor;
      if(sShape=="circle"){
        ctx.beginPath();
        ctx.arc(food.x*box+box/2,food.y*box+box/2,box/2,0,2*Math.PI);
        ctx.fill();
      } else {
        ctx.fillRect(food.x*box,food.y*box,box,box);
      }
      if(isPaused){
        ctx.fillStyle="rgba(0,0,0,0.5)";
        ctx.fillRect(0,0,w,h);
        ctx.fillStyle="#fff";
        ctx.shadowColor="#fff";
        ctx.shadowBlur=15;
        ctx.font="30px sans-serif";
        ctx.textAlign="center";
        ctx.fillText("PAUSED",w/2,h/2);
      }
    }
    function moveSnake(){
      let head={x:snake[0].x,y:snake[0].y};
      if(direction=="LEFT")head.x--;
      if(direction=="RIGHT")head.x++;
      if(direction=="UP")head.y--;
      if(direction=="DOWN")head.y++;
      if(head.x<0||head.x>=cols||head.y<0||head.y>=rows){
        gameOver();
        return;
      }
      for(let i=0;i<snake.length;i++){
        if(snake[i].x==head.x&&snake[i].y==head.y){
          gameOver();
          return;
        }
      }
      snake.unshift(head);
      if(head.x==food.x&&head.y==food.y){
        score++;
        scoreEl.textContent=score;
        if(moveInterval>50){
          moveInterval-=10;
        }
        spawnFood();
      } else {
        snake.pop();
      }
    }
    function gameOver(){
      isOver=true;
      fs.textContent=score;
      goDiv.style.display="flex";
    }
    function restartGame(){
      score=0;
      scoreEl.textContent=0;
      snake=[];
      length=3;
      for(let i=0;i<length;i++){
        snake.push({x:Math.floor(cols/2)-i,y:Math.floor(rows/2)});
      }
      direction="RIGHT";
      moveInterval=Number(snakeSpeedEl.value)||200;
      isOver=false;
      isPaused=false;
      goDiv.style.display="none";
      spawnFood();
      lastFrame=0;
      timeSinceMove=0;
      requestAnimationFrame(loop);
    }
    function measurePing(){
      let start=performance.now();
      fetch("?ping").then(()=>{
        pingVal.textContent=(performance.now()-start).toFixed(0);
      });
    }
    function applySettings(){
      snakeName=snakeNameEl.value||"Snake";
      moveInterval=Number(snakeSpeedEl.value)||200;
      fDist=Number(foodDistEl.value)||0;
      snakeColor=snakeColorEl.value||"#0f5";
      foodColor=foodColorEl.value||"#f33";
      bgColor=bgColorEl.value||"#000000";
      sShape=snakeShapeEl.value;
      settingsPanel.style.display="none";
    }
    settingsBtn.onclick=function(){
      settingsPanel.style.display=settingsPanel.style.display=="flex"?"none":"flex";
    };
  </script>
</body>
</html>
)====";
  page.replace("{{IP}}", WiFi.localIP().toString());
  page.replace("{{MAC}}", WiFi.macAddress());
  page.replace("{{HOST}}", WiFi.hostname());
  page.replace("{{RSSI}}", String(WiFi.RSSI()));
  page.replace("{{CHIPID}}", String(ESP.getChipId()));
  page.replace("{{FREEHEAP}}", String(ESP.getFreeHeap()));
  return page;
}

void handleRoot() {
  if (server.uri() == "/?ping") {
    server.send(200, "text/plain", "pong");
    return;
  }
  String content = generatePage();
  server.send(200, "text/html", content);
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  server.onNotFound(handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
