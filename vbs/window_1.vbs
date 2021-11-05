'badger
Set win = New Window
win.SetTitle = "Move:"
win.Icon = "%WINDIR%\System32\OpenWith.exe"
win.ContextMenu = "no"
win.Scroll = "no"
win.SetHeight = 140

win.AddStyles = "body{text-align:center;margin-top:5px;}div{padding:15px;font-size:11pt;}"
win.AddStyles = "input{border:0;border-radius:2px;padding:5px 10px;margin:5px;background-color:#e2e2e2;}"

win.AddContent = "<div>Click a button...</div>"

win.AddContent = "<input type='button' value='Continue' onclick='send(true)'>"
win.AddContent = "<input type='button' value='Cancel' onclick='send(false)'>"
	
answer = win.Create()
If answer Then MsgBox "Continuing..." Else MsgBox "Quitting."	

'_____

Class Window
	Private title, style, body, options, width, height, xpos, ypos	
	Private Sub Class_Initialize()
		title = "&nbsp;" : width = 350 : height = 250
		xpos = "(screen.width - " & width & ")/2"
		ypos = "(screen.height -" & height & ")/2" 
		style = "html{display:table;}body{display:table-cell;font-family:Arial;background-color:#f6f6f6;}html,body{width:100%;height:100%;margin:0;}"
	End Sub	
	Public Property Let SetTitle(str)		 : title = str				 : End Property	 
	Public Property Let SetWidth(num)		 : width = num				 : End Property 
	Public Property Let SetHeight(num)		: height = num				: End Property
	Public Property Let SetXPosition(num) : xpos = num					: End Property 
	Public Property Let SetYPosition(num) : ypos = num					: End Property 
	Public Property Let AddStyles(css)		: style = style & css : End Property 
	Public Property Let AddContent(html)	: body = body & html	: End Property		
	Public Property Let ApplicationName(str)		: options = options & "applicationName='" & str & "' "		: End Property
	Public Property Let Border(thick_thin_none) : options = options & "border='" & thick_thin_none & "' " : End Property
	Public Property Let Caption(yes_no)				 : options = options & "caption='" & yes_no & "' "				 : End Property
	Public Property Let ContextMenu(yes_no)		 : options = options & "contextMenu='" & yes_no & "' "		 : End Property
	Public Property Let Icon(path)							: options = options & "icon='" & path & "' "							: End Property
	Public Property Let MaximizeButton(yes_no)	: options = options & "maximizeButton='" & yes_no & "' "	: End Property
	Public Property Let MinimizeButton(yes_no)	: options = options & "minimizeButton='" & yes_no & "' "	: End Property
	Public Property Let Scroll(yes_no)					: options = options & "scroll='" & yes_no & "' "					: End Property
	Public Property Let Selection(yes_no)			 : options = options & "selection='" & yes_no & "' "			 : End Property
	Public Property Let ShowInTaskBar(yes_no)	 : options = options & "showInTaskBar='" & yes_no & "' "	 : End Property
	Public Property Let SingleInstance(yes_no)	: options = options & "singleInstance='" & yes_no & "' "	: End Property
	Public Property Let SysMenu(yes_no)				 : options = options & "sysMenu='" & yes_no & "' "				 : End Property
	Public Property Let WindowState(normal_minimize_maximize) : options = options & "windowState='" & normal_minimize_maximize & "' " : End Property	
	Public Function Create()
		Create = CreateObject("WScript.Shell").Exec( _
			"mshta ""about:<!DOCTYPE html><html><head><meta http-equiv='X-UA-Compatible' content='IE=9'><title>" & title & _
			"</title><hta:application " & options & "/><style>" & style & "</style>" & _
			"<script>var c=true;function send(s){c=false;new ActiveXObject('Scripting.FileSystemObject').GetStandardStream(1).WriteLine(s);close();}" & _
			"window.onbeforeunload=function(){if(c)send(0);};resizeTo(" & width & "," & height & ");moveTo(" & xpos & "," & ypos & ");</script>" & _
			"</head><body>" & body & "</body></html>""" _
		).StdOut.ReadLine()
	End Function 
End Class