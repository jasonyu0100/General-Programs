def showTestCaseInfo(inputs,outputs,receivedOutputs):
  print('TEST CASE FAILED!')
  print('inputs:',inputs)
  print('received Output:',receivedOutputs)
  print('actual Output:',outputs)

def testFunction(testingFunction,testCases):
  for inputs,outputs in testCases:
    failedTestCase = False
    receivedOutputs = testingFunction(*inputs)
    if type(outputs) != type(receivedOutputs):
      print('outputs not of same type!')
      print('output type:',type(outputs),'received output type:',type(receivedOutputs))
      failedTestCase = True
    elif type(outputs) in {list,tuple}:
      if len(outputs) != len(receivedOutputs):
        print('received and actual outputs not of same length')
        failedTestCase = True
      sameOutputCheck = all(receivedOutputs[index] == outputs[index] for index in len(outputs))
      if sameOutputCheck == False:
        failedTestCase = True
    else:
      if outputs != receivedOutputs:
        failedTestCase = True
    if failedTestCase:
      showTestCaseInfo(inputs,outputs,receivedOutputs)
      break
    else:
      print('TEST CASE PASSED!','inputs:',inputs,'outputs:',outputs)
  else:
    print('ALL TESTS PASSED!')

# testCases = [
#   ([1,2],2),
#   ([3,4],12),
#   ([4,5],20),
#   ]

# def multiply(x,y):
#   return x,y

# testFunction(multiply,testCases)


