PROGRAM BISSECCAO
    IMPLICIT NONE
    REAL:: VALUE, RESULT
    CHARACTER(LEN=32):: INPUT
    CALL GETARG(1, INPUT)
    READ(INPUT, *) VALUE
    PRINT *, GET_SQRT(VALUE, 1E-5)

    CONTAINS
    FUNCTION GET_SQRT(VALUE, TOLERANCE) RESULT(P)
        REAL, INTENT(IN):: VALUE, TOLERANCE
        REAL, PARAMETER:: MAX_ITERATION = 1E+6
        REAL:: P, FP, INITIAL, FINAL, AUX
        INTEGER:: I = 0
        INITIAL = 0
        FINAL = VALUE
100     IF ((I .LT. MAX_ITERATION)) THEN
            AUX = ((FINAL - INITIAL) / 2)
            P = INITIAL + AUX
            FP = P ** 2 - VALUE
            IF ((FP.EQ.0).OR.(AUX.LT.TOLERANCE)) RETURN
            IF (((INITIAL ** 2) - VALUE) * FP .GT. 0) THEN
                INITIAL = P
            ELSE
                FINAL = P
            END IF
            I = I + 1
            GOTO 100
        ELSE
            P = -1
        END IF
    END FUNCTION GET_SQRT
END PROGRAM BISSECCAO