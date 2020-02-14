import * as ActionTypes from '../actionTypes/piecesActionTypes';

export const pieceGoingDown = () => {
  return {
    type: ActionTypes.PIECE_GO_DOWN,
  };
};

export const pieceGoingRight = () => {
  return {
    type: ActionTypes.PIECE_GO_RIGHT,
  };
};

export const pieceGoingLeft = () => {
  return {
    type: ActionTypes.PIECE_GO_LEFT,
  };
};

export const pieceGoingStraightDown = () => {
  return {
    type: ActionTypes.PIECE_GO_STRAIGHT_DOWN,
  };
};
