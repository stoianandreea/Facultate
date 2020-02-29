window.onload = function(){
	document.getElementById("albastreste").onclick = albastreste; 
	// in loc de null scriem albastreste fara paranteze pentru ca avem nevoie de referinta, nu de valoare returnata

}

function albastreste(){
	pgfs = document.querySelectorAll("p");
	for(pg of pgfs){
		var stil = getComputedStyle(pg);  // ia stilul din css (ii face o copie, deci nu poate fi modificat aici)
		if(stil.color == "rgb(255, 0, 0)"){
			pg.style.color = "blue";
		}
	}
	/*
	//de observat si apoi de comentat
	alert(pgfs[0].style.color)
	pgfs[0].style.color = "blue"
	alert(pgfs[0].style.color)
	*/
	
}