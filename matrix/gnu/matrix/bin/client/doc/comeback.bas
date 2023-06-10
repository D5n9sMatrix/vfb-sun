'WINDOWTITLE("AFFIRMATIONS")
SCREEN 19

DIM SHARED i AS INTEGER = 0
DIM SHARED answer AS STRING, tmp AS STRING
REDIM SHARED buffer(0) AS STRING



'1 getkeys function

FUNCTION _
	getKeys(_
	BYREF keysToCatch AS CONST STRING) _
	AS STRING
	
	DIM AS STRING _
	k
	
	DO
        k = > INKEY()
       
        SLEEP(1 , 1)
    LOOP UNTIL (INSTR(keysToCatch , k))
	
	'CLEAR keyboard buffer
	DO WHILE (LEN(INKEY()) > 0)
        SLEEP(1 , 1)
    LOOP
	
	RETURN(k)
END FUNCTION

SUB cp(row AS INTEGER, s AS STRING)
   LOCATE row, (100 - LEN(s)) / 2 : PRINT s
END SUB

SUB sappend(arr() AS STRING, temp AS STRING)
    arr(UBOUND(arr)) = temp
   REDIM PRESERVE arr(LBOUND(arr) TO UBOUND(arr) +1) AS STRING
   
END SUB
SUB add_affirmation()
DIM h AS LONG = FREEFILE()
CLS
INPUT "PLEASE ENTER SOMETHING POSITIVE ABOUT YOURSELF: ", answer

OPEN "affirmations.txt" FOR APPEND AS #h
print #h, answer
CLOSE #h
PRINT
PRINT "PRESS ANY KEY..."
SLEEP

END SUB

SUB show_affirmations()
DIM h AS LONG = FREEFILE()
CLS

OPEN "affirmations.txt" FOR input AS #h
WHILE NOT EOF(h)
LINE INPUT #h, tmp
SAPPEND buffer(), tmp
WEND
CLOSE #h

PRINT "YOUR AFFIRMATIONS ARE:"

DO
   PRINT buffer(i)
   i += 1
    if i mod 5 = 0 then
        sleep
    end if
LOOP UNTIL i = UBOUND(buffer)
PRINT
PRINT "PRESS ANY KEY..."
SLEEP
END SUB

SUB main
   DO
   DIM k AS STRING
   CLS
   CP 1, "POSITIVE AFFIRMATION PROGRAM"
   CP 3, "PRESS KEY 1 TO MAKE AN AFFIRMATION"
   CP 5, "PRESS KEY 2 TO VIEW YOUR AFFIRMATIONS"
   CP 7, "PRESS KEY 3 TO DELETE DATABASE AND START FRESH"
   CP 9, "PRESS ESC KEY TO EXIT PROGRAM"
   k = GETKEYS("123" + CHR(27))
   IF k = CHR(27) THEN
      END
   ELSEIF k = "1" THEN
      ADD_AFFIRMATION()
   ELSEIF k = "2" THEN
      show_affirmations()
   ELSEIF k = "3" THEN
     Dim result As Integer = KILL("affirmations.txt")
     IF result <> 0 THEN
        CLS:PRINT "ERROR TRYING TO DELETE FILE affirmations.txt MAYBE THE FILE DOESN'T EXITS? PLEASE MAKE AN AFFIRMATION FIRST :)"
        sleep
     ELSE
        CLS
        DIM h AS LONG = FREEFILE()
        OPEN "affirmations.txt" FOR APPEND AS #h
        CLOSE #h
        PRINT "TEXT FILE BEEN ERASED"
        SLEEP
     ENDIF
   
   ENDIF

   LOOP
   
END SUB

MAIN()