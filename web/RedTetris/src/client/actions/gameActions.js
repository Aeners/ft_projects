import * as ActionTypes from '../actionTypes/gameActionTypes';

export const startTheGame = () => {
  return {
    type: ActionTypes.START_GAME,
  };
};

export const finishTheGame = () => {
  return {
    type: ActionTypes.FINISH_GAME,
  };
};
