import { connect } from 'react-redux';
import Board from './Board';

import {
  pieceGoingDown,
  pieceGoingLeft,
  pieceGoingRight,
  // pieceGoingStraightDown,
} from '../../actions/piecesActions';

const mapStateToProps = state => {
  return {
    block: state.piece.block,
    position: state.piece.position,
  };
};

const mapDispatchToProps = dispatch => {
  return {
    pieceGoingDown: () => {
      dispatch(pieceGoingDown());
    },
    pieceGoingLeft: () => {
      dispatch(pieceGoingLeft());
    },
    pieceGoingRight: () => {
      dispatch(pieceGoingRight());
    },
  };
};

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(Board);
