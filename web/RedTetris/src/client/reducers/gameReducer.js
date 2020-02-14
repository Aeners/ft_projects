import * as ActionTypes from '../actionTypes/gameActionTypes';

const initialState = {
  player1: '',
  player2: '',
  gameHasStarted: false,
  gameIsFinished: false,
};

const game = (state = initialState, { type }) => {
  switch (type) {
    case ActionTypes.START_GAME:
      return {
        ...state,
        gameHasStarted: true,
      };
    case ActionTypes.FINISH_GAME:
      return {
        ...state,
        gameIsFinished: true,
      };
    default:
      return state;
  }
};

export default game;
