window.onload = function(){
	var nr = localStorage.getItem("numar");
	if(!nr)
		nr = 1;
	else
		nr = parseInt(nr) + 1;
	localStorage.setItem("numar", nr);
	document.body.innerHTML = `<p>${nr}</p>`; // sau "<p>" + nr + "</p>"; 
	btn = document.createElement("button")
	document.body.appendChild(btn);
	btn.innerHTML = "sterge";
	btn.onclick = function(){
		localStorage.removeItem("numar");
		this.previousElementSibling.innerHTML = 0;
	}
}