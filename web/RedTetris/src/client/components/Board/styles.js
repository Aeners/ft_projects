import styled from 'styled-components';

export const SBoard = styled.div`
  height: 800px;
  width: 400px;
  background-color: grey;
  z-index: 1;
  display: inline-block;
  margin-top: 40px;
`;

export const SWrapper = styled.div`
  height: 100%;
  width: 100%;
  display: flex;
  flex-direction: row;
  flex-wrap: wrap;
`;

export const SBlock = styled.div`
  height: 38px;
  width: 38px;
  border: 1px solid black;
  background-color: ${props => (props.color ? props.color : 'grey')};
  -moz-box-shadow: inset 0 5px #000000;
  -webkit-box-shadow: inset 0 0 5px #000000;
  box-shadow: inset 0 0 5px #000000;
`;
