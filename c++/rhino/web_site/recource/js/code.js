//badger
function copy_txt(id){
	var txt=document.getElementById(id);

	window.getSelection().selectAllChildren(txt);

	navigator.clipboard.writeText(txt.value);
}
function copy_code(){
	copy_txt("txt");
}
/*function copy_txt(id){
	var txt=document.getElementById(id);
	window.getSelection().selectAllChildren(txt);
	execCommand("Copy");
}*/