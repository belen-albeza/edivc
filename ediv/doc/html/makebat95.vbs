'
' Este script debe ser usado en windows 95, 98 y Me para compilar la documentaci�n.
' MakedokNT.bat no funcionar� porque el MSDOS de win9x no usa nombres largos por
' defecto :P y Doku requiere nombres largos.
' Primero hay que ejecutar este script, que rastrear� los .dok que haya en el
' directorio actual y crear� un makedok95.bat que llama a Sion Doku usando nombres
' largos. Entonces ejecutamos makedok95.bat y Doku entrar� en acci�n.
' Me hubiera gustado simplificar un poco m�s el proceso, pero no puedo llamar a
' Doku desde el windows scripting host (menuda mierda, dicho sea de paso. Es en
' estos momentos cuando m�s echo de menos al Bash o al AppleScript).
'
' Er_Makina
'

dim fs,f,bat,fil,c
Set fs=CreateObject("Scripting.FileSystemObject")
Set f=fs.getfolder(".").files
set bat=fs.opentextfile("makedok95.bat",2,true)
bat.write ":: makedok95.bat generado por makebat95.vbs" & vbcrlf
bat.write ":: Ejecuta este script para compilar la documentaci�n." & vbcrlf
bat.write ":: Si a�ades o quitas un documento, ejecuta makebat95.vbs para actualizar el bat." & vbcrlf & vbcrlf
c=0
for each fil in f
if lcase(fs.getextensionname(fil.path))="dok" or lcase(fs.getextensionname(fil.path))="doku" then
bat.write "..\doku.exe " & fil.name & vbcrlf
c=c+1
end if
next
bat.close
msgbox "Encontrados " & c & " fichero(s)." & vbcrlf & "Ahora ejecuta makedok95.bat y la magia de Doku har� el resto... ;)"
