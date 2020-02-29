
window.onmousedown = function(e){
	var dv = document.createElement("div");
	document.body.appendChild(dv);
	dv.style.border = "1px solid black";
	dv.style.position = "absolute";
	dv.style.top = dv.style.left = "0";     // doar pentru 0 pot sa nu pun unitatea
	dv.style.width = e.clientX + "px";
	dv.style.height = e.clientY + "px";
	if(e.shiftKey)
		dv.style.background = "red";
	else
		dv.style.background = "blue";
	dv.id = "dreptunghi";
}

window.onmouseup = function(e){
	var dv = document.getElementById("dreptunghi");
	if(dv)
		dv.remove();
	
}