const storeStateMiddleWare = ({ getState }) => {
  return next => action => {
    const returnValue = next(action);
    // eslint-disable-next-line
    window.top.state = getState();
    return returnValue;
  };
};

export default storeStateMiddleWare;
