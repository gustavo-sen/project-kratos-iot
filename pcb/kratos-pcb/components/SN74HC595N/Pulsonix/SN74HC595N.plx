PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//181996/949171/2.50/16/3/Integrated Circuit

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "c113_h73"
		(holeDiam 0.73)
		(padShape (layerNumRef 1) (padShapeType Ellipse)  (shapeWidth 1.13) (shapeHeight 1.13))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 1.13) (shapeHeight 1.13))
	)
	(padStyleDef "s113_h73"
		(holeDiam 0.73)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.13) (shapeHeight 1.13))
		(padShape (layerNumRef 16) (padShapeType Rect)  (shapeWidth 1.13) (shapeHeight 1.13))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "DIP794W53P254L1930H508Q16N" (originalName "DIP794W53P254L1930H508Q16N")
		(multiLayer
			(pad (padNum 1) (padStyleRef s113_h73) (pt -3.97, 8.89) (rotation 90))
			(pad (padNum 2) (padStyleRef c113_h73) (pt -3.97, 6.35) (rotation 90))
			(pad (padNum 3) (padStyleRef c113_h73) (pt -3.97, 3.81) (rotation 90))
			(pad (padNum 4) (padStyleRef c113_h73) (pt -3.97, 1.27) (rotation 90))
			(pad (padNum 5) (padStyleRef c113_h73) (pt -3.97, -1.27) (rotation 90))
			(pad (padNum 6) (padStyleRef c113_h73) (pt -3.97, -3.81) (rotation 90))
			(pad (padNum 7) (padStyleRef c113_h73) (pt -3.97, -6.35) (rotation 90))
			(pad (padNum 8) (padStyleRef c113_h73) (pt -3.97, -8.89) (rotation 90))
			(pad (padNum 9) (padStyleRef c113_h73) (pt 3.97, -8.89) (rotation 90))
			(pad (padNum 10) (padStyleRef c113_h73) (pt 3.97, -6.35) (rotation 90))
			(pad (padNum 11) (padStyleRef c113_h73) (pt 3.97, -3.81) (rotation 90))
			(pad (padNum 12) (padStyleRef c113_h73) (pt 3.97, -1.27) (rotation 90))
			(pad (padNum 13) (padStyleRef c113_h73) (pt 3.97, 1.27) (rotation 90))
			(pad (padNum 14) (padStyleRef c113_h73) (pt 3.97, 3.81) (rotation 90))
			(pad (padNum 15) (padStyleRef c113_h73) (pt 3.97, 6.35) (rotation 90))
			(pad (padNum 16) (padStyleRef c113_h73) (pt 3.97, 8.89) (rotation 90))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -4.945 10.095) (pt 4.945 10.095) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 4.945 10.095) (pt 4.945 -10.095) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 4.945 -10.095) (pt -4.945 -10.095) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -4.945 -10.095) (pt -4.945 10.095) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -3.3 9.845) (pt 3.3 9.845) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 3.3 9.845) (pt 3.3 -9.845) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 3.3 -9.845) (pt -3.3 -9.845) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -3.3 -9.845) (pt -3.3 9.845) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -3.3 8.575) (pt -2.03 9.845) (width 0.025))
		)
		(layerContents (layerNumRef 18)
			(line (pt -4.535 9.845) (pt 3.3 9.845) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3.3 -9.845) (pt 3.3 -9.845) (width 0.2))
		)
	)
	(symbolDef "SN74HC595N" (originalName "SN74HC595N")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 3) (pt 0 mils -200 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -225 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 4) (pt 0 mils -300 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -325 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 5) (pt 0 mils -400 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -425 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 6) (pt 0 mils -500 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -525 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 7) (pt 0 mils -600 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -625 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 8) (pt 0 mils -700 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 230 mils -725 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 9) (pt 1200 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 970 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 10) (pt 1200 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 970 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 11) (pt 1200 mils -200 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 970 mils -225 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 12) (pt 1200 mils -300 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 970 mils -325 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 13) (pt 1200 mils -400 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 970 mils -425 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 14) (pt 1200 mils -500 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 970 mils -525 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 15) (pt 1200 mils -600 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 970 mils -625 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 16) (pt 1200 mils -700 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName true)) (pinName (text (pt 970 mils -725 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(line (pt 200 mils 100 mils) (pt 1000 mils 100 mils) (width 6 mils))
		(line (pt 1000 mils 100 mils) (pt 1000 mils -800 mils) (width 6 mils))
		(line (pt 1000 mils -800 mils) (pt 200 mils -800 mils) (width 6 mils))
		(line (pt 200 mils -800 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 1050 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 1050 mils 200 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "SN74HC595N" (originalName "SN74HC595N") (compHeader (numPins 16) (numParts 1) (refDesPrefix IC)
		)
		(compPin "1" (pinName "QB") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "QC") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "3" (pinName "QD") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "4" (pinName "QE") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "5" (pinName "QF") (partNum 1) (symPinNum 5) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "6" (pinName "QG") (partNum 1) (symPinNum 6) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "7" (pinName "QH_1") (partNum 1) (symPinNum 7) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "8" (pinName "GND") (partNum 1) (symPinNum 8) (gateEq 0) (pinEq 0) (pinType Power))
		(compPin "16" (pinName "VCC") (partNum 1) (symPinNum 9) (gateEq 0) (pinEq 0) (pinType Power))
		(compPin "15" (pinName "QA") (partNum 1) (symPinNum 10) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "14" (pinName "SER") (partNum 1) (symPinNum 11) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "13" (pinName "__OE") (partNum 1) (symPinNum 12) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "12" (pinName "RCLK") (partNum 1) (symPinNum 13) (gateEq 0) (pinEq 0) (pinType Input))
		(compPin "11" (pinName "SRCLK") (partNum 1) (symPinNum 14) (gateEq 0) (pinEq 0) (pinType Input))
		(compPin "10" (pinName "__SRCLR") (partNum 1) (symPinNum 15) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "9" (pinName "QH_2") (partNum 1) (symPinNum 16) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "SN74HC595N"))
		(attachedPattern (patternNum 1) (patternName "DIP794W53P254L1930H508Q16N")
			(numPads 16)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
				(padNum 5) (compPinRef "5")
				(padNum 6) (compPinRef "6")
				(padNum 7) (compPinRef "7")
				(padNum 8) (compPinRef "8")
				(padNum 9) (compPinRef "9")
				(padNum 10) (compPinRef "10")
				(padNum 11) (compPinRef "11")
				(padNum 12) (compPinRef "12")
				(padNum 13) (compPinRef "13")
				(padNum 14) (compPinRef "14")
				(padNum 15) (compPinRef "15")
				(padNum 16) (compPinRef "16")
			)
		)
		(attr "Mouser Part Number" "595-SN74HC595N")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Texas-Instruments/SN74HC595N?qs=IEl3ej0IqwBTHkYa8XPoMQ%3D%3D")
		(attr "Manufacturer_Name" "Texas Instruments")
		(attr "Manufacturer_Part_Number" "SN74HC595N")
		(attr "Description" "8-Bit Shift Registers With 3-State Output Registers")
		(attr "<Hyperlink>" "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf")
		(attr "<Component Height>" "5.08")
		(attr "<STEP Filename>" "SN74HC595N.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=2.47")
		(attr "<STEP Rotation>" "X=90;Y=0;Z=0")
	)

)
