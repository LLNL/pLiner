
class loopStruct:
  def __init__(self, start, end):
    self.start, self.end = start, end
    self.innerloops = []
  def isInnerLoop(self, start, end):
    return start>self.start and end<self.end
  def addInnerLoop(self, start, end):
    self.innerloops.append([start, end])
  def getLoop(self):
    return self.start, self.end
  def getInnerLoops(self):
    return self.innerloops

class loopList:
  def __init__(self, _forloops):
    self.loops = []
    for start, end in _forloops:
      added = False
      for l in self.loops:
        if l.isInnerLoop(start, end):
	  l.addInnerLoop(start, end)
          added = True
      if not added:
        loop = loopStruct(start, end)
        self.loops.append(loop)

  def getLoopList(self):
    return self.loops 


def splitloops(_forloops):
  _forloops.sort(key=lambda s:s[0])
  looplist = loopList(_forloops)
  return looplist.getLoopList()

