import { Nicholas } from "./src/nonchalant-nicholas.js";
const container = document.getElementById("app");

//make class to do html components
//do this dynamically since we don't know how many spice spaces we have
const spiceRack = ["salt", "pepper", "garlic powder", "onion powder", "paprika"];
const newNick = new Nicholas(spiceRack);
container.innerHTML = "";
container.appendChild(newNick.render())
