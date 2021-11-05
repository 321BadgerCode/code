'badger
set wss=wScript.createObject("wScript.shell")
set fso=createObject("scripting.fileSystemObject")

public function sd():sd=fso.getParentFolderName(wScript.scriptFullName):end function

class folderz
	private d
	public default function init(A1):d=A1:set init=me:end function
	public function create():fso.createFolder(d):end function
	public function exists():exists=fso.folderExists(d):end function
	public property get dir():dir=d:end property
end class
class filez
	private l:private o
	private function leave():o.close():set o=nothing:end function
	public d:public n:public t
	public default function init(A1,A2,A3):d=A1:n=A2:t=A3:l=d+n+t:set init=me:end function
	public function exists():exists=fso.fileExists(l):end function
	public function open(A1):set o=fso.openTextFile(l,A1):leave():end function
	public function create():set o=fso.createTextFile(l,true):leave():end function
	public function write(A1):set o=fso.openTextFile(l,2):o.writeLine(A1):leave():end function
	public function text():set o=fso.openTextFile(l,1):b1=o.readAll():leave():text=b1:end function
	public property get loc():loc=l:end property
	public property get obj():obj=o:end property
	'function lines()
	'	do while
	'		b2=o.readLine()
	'		msgbox(b2)
	'	loop until o.atEndOfStream
	'end function
end class
class myz
	private fn
	public default function init():fn=uCase(wScript.scriptFullName)+"!":set init=me:end function
	public function msg(A1):msg=msgBox(A1,0,fn):end function
	public function input(A1):input=inputBox(A1,fn):end function
end class
public sub main
	set my=(new myz)()
	set folder=(new folderz)(sd()+"\!\"):if not folder.exists() then:folder.create():end if
	set file=(new filez)(folder.dir(),"test",".txt"):if not file.exists() then:file.create():end if
	a1=my.input("String to put in .txt file")
	file.write(a1)
	wScript.quit()
end sub
main()