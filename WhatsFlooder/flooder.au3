;; 
;; Script para floodar o Whatsapp com mensagem aleatórias (huehue)
;; Autor: Lucas Vieira de Jesus
;;

#include <WinAPISys.au3>
#include <WinAPI.au3>
#include <String.au3>
#include <ScreenCapture.au3>

func Floodar($delay = 1000)
	$count = 0
	$buffer = ""
	$title = "Whatsapp Web"
	
	;; Configura a semente
	$seed = _WinAPI_GetTickCount()
	SRandom($seed)

	;; Loop (pressionamento das teclas)
	while 1
		WinWait($title)

		;; Gera uma string aleatória
		while $count < 26
			$buffer = $buffer & chr(random(97,122))
			$count = $count + 1
		wend

		;; Simula o pressionamento da tecla
		send($buffer & "{SPACE}{ENTER}")
		$count = 0
		$buffer = ""
		sleep($delay)
	wend
endFunc

;; Função principal do programa
func Main()
	Floodar(5000)
EndFunc

Main()