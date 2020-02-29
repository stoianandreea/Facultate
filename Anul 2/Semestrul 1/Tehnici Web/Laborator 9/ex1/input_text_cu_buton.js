window.onload = function(){
	var btn = document.getElementById("buton");
	btn.onclick = function(){
		val = document.getElementById("textbox").value;
		var lst = document.getElementById("lista"); //daca nu exista, returneaza null
		if(!lst){
			lst = document.createElement("ol");
			lst.id = "lista";
			document.body.appendChild(lst);
			//folosim local storage
			lst.innerHTML = localStorage.getItem("listuta");
		}
		var li = document.createElement("li");
		li.innerHTML = val;
		lst.appendChild(li);
		//
		localStorage.setItem("listuta", lst.innerHTML);
	}
}

//apare lista doar la click pe buton
//ca sa se incarce local storage la incarcare => ? mutam if ul la inceput si inca ceva