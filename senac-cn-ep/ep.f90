PROGRAM EXERCICIO_PROGRAMA
    IMPLICIT NONE
    REAL, PARAMETER:: M = 0.15
    INTEGER:: DIM, I
    REAL(8), DIMENSION(:,:), ALLOCATABLE:: MATRIX, S_MATRIX, NORM_MATRIX
    READ (*, *) DIM
    CALL ALLOCATE_MATRIX(MATRIX, S_MATRIX, DIM)
    
    MATRIX = (1 - M) * MATRIX(:, :)
    S_MATRIX = M * S_MATRIX(:, :)

    NORM_MATRIX = MATRIX + S_MATRIX

    CALL GET_RESULT(NORM_MATRIX, DIM)

    DEALLOCATE(MATRIX)
    DEALLOCATE(S_MATRIX)
    
    CONTAINS
    REAL FUNCTION GET_DIFFERECE(ACTUAL_VEC, PREV_VEC, SIZE)
        INTEGER, INTENT(IN):: SIZE
        REAL(8), INTENT(IN), DIMENSION(SIZE):: ACTUAL_VEC, PREV_VEC
        REAL(8), DIMENSION(SIZE):: AUX
        INTEGER:: I
        REAL(8):: SUM = 0.0
        AUX = ACTUAL_VEC - PREV_VEC
        DO I = 1, SIZE
            SUM = SUM + AUX(I) 
        END DO
        GET_DIFFERECE = SUM
    END FUNCTION GET_DIFFERECE

    SUBROUTINE GET_RESULT(NORM_MATRIX, SIZE)
        INTEGER, INTENT(IN):: SIZE
        REAL(8), INTENT(IN), DIMENSION(SIZE, SIZE):: NORM_MATRIX
        REAL(8), PARAMETER:: STOP_CONDITION = 10E-5
        REAL(8), DIMENSION(SIZE):: CURRENT_VEC, PREV_VEC, AUX
        CURRENT_VEC(:) = 1.D0 / SIZE
        AUX = M * CURRENT_VEC
200     PREV_VEC = CURRENT_VEC
        CURRENT_VEC =  (1 - M) * MATMUL(NORM_MATRIX, PREV_VEC) + AUX
        IF (GET_DIFFERECE(CURRENT_VEC, PREV_VEC, SIZE) .LT. STOP_CONDITION) THEN
            PRINT*, CURRENT_VEC(:)
        ELSE 
            GOTO 200
        END IF
    END SUBROUTINE GET_RESULT

    SUBROUTINE ALLOCATE_MATRIX(PRIMARY_MATRIX, SECONDARY_MATRIX, SIZE)
        REAL(8), INTENT(INOUT), DIMENSION(:, :), ALLOCATABLE:: PRIMARY_MATRIX, SECONDARY_MATRIX
        INTEGER, INTENT(IN):: SIZE
        INTEGER:: I
        ALLOCATE(PRIMARY_MATRIX(SIZE, SIZE))
        ALLOCATE(SECONDARY_MATRIX(SIZE, SIZE))
        DO I = 1, SIZE
            READ (*, *) PRIMARY_MATRIX(I, :)
            SECONDARY_MATRIX(I, :) = 1.D0 / SIZE
        END DO
    END SUBROUTINE ALLOCATE_MATRIX
END PROGRAM EXERCICIO_PROGRAMA