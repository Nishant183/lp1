def katam(board):
    for i in range(0,3):
        for j in range(0,3):
            if board[i][j] == '-':
                return False
    return True            

def kon_jeeta(board):
    for i in range(0,3):
        if (board[i][0] == board[i][1]) and (board[i][1] == board[i][2]):
            if board[i][0] == 'O':
                return 10
            elif board[i][0] == 'X':
                return -10 

    for i in range(0,3):
        if (board[0][i] == board[1][i]) and (board[1][i] == board[2][i]):
            if board[0][i] == 'O':
                return 10
            elif board[0][i] == 'X':
                return -10  

    if (board[0][0] == board[1][1]) and (board[1][1] == board[2][2]):
        if board[0][0] == 'O':
            return 10
        elif board[0][0] == 'X':
            return -10

    if (board[2][0] == board[1][1]) and (board[1][1] == board[0][2]):
        if board[0][2] == 'O':
            return 10
        elif board[0][2] == 'X':
            return -10

    return 0

def MinMax(board,depth,isMax):
    score = kon_jeeta(board)
    if score == 10:
        return score-depth
    if score == -10:
        return score+depth  

    if katam(board) == True:
        return 0

    if isMax == True:
        best = 1000
        for i in range(0,3):
            for j in range(0,3):
                if board[i][j] == '-':
                    board[i][j] = 'X'
                    temp = MinMax(board,depth+1,not(isMax))
                    if temp < best:
                        best = temp
                    board[i][j] = '-'
        return best
    else:
        best = -1000
        for i in range(0,3):
            for j in range(0,3):
                if board[i][j] == '-':
                    board[i][j] = 'O'
                    temp = MinMax(board,depth+1,not(isMax))
                    # print(temp)
                    if temp > best:
                        best = temp
                    board[i][j] = '-'
        return best

def bestMove(board):
    x_cor = -1
    y_cor = -1
    best_value = -1000

    for i in range(0,3):
        for j in range(0,3):
            if board[i][j] == '-':
                board[i][j] = 'O'
                temp = MinMax(board,0,True)
                board[i][j] = '-'

                if temp > best_value:
                    best_value = temp
                    x_cor = i
                    y_cor = j

    return (x_cor,y_cor)

board = [['-','-','-'],['-','-','-'],['-','-','-']]

while True:
    for i in range(0,3):
        for j in range(0,3):
            print(board[i][j] + str(' '),end='')
            if j != 2:
                print('| ',end='')
        print('')
    x,y = input('Enter Value of Cordinate : ').split(' ')
    x = int(x)
    y = int(y)
    if board[x][y] != '-':
        print('Invalid Move')
        continue
    board[x][y] = 'X'

    if katam(board) == True:
        print("It's a Draw..")
        break

    if kon_jeeta(board) == -10:
        print("You Win..")   
        break
    n_x,n_y = bestMove(board)
    board[n_x][n_y] = 'O'
    if kon_jeeta(board) == 10:
        print("You Lose..")
        for i in range(0,3):
            for j in range(0,3):
                print(board[i][j] + str(' '),end='')
                if j != 2:
                    print('| ',end='')
            print('')
        break  
