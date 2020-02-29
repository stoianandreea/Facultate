
window.onload = function(){
	v = ["Mercur","Marte","Venus","Jupiter","un asteroid oarecare","o cometa in trecere"];
	var sel = document.createElement("select");
	document.body.appendChild(sel);
	for(el of v){
		var opt = document.createElement("option");
		opt.innerHTML = opt.value = el;
		sel.appendChild(opt);
	}
	sel.onchange = function(){
		var p = document.createElement("p");
		document.body.appendChild(p);
		p.innerHTML = "Am intalnit un extraterestru de pe " + this.value;
	}
}