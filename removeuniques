def checkio(data: list) -> list:
    rechecks = 1
    runscan = True
    while runscan == True:
        for i in data:
             if data.count(i) <2:
                 data.remove(i)
                 rechecks+=1
                #need to double check now
        if rechecks >0:
            runscan = True
            rechecks-=1
        else:
            runscan = False       
    return data
