"""empty message

Revision ID: 91fa482ba2b4
Revises: dc736d1268df
Create Date: 2023-06-19 21:14:38.304052

"""
from alembic import op
import sqlalchemy as sa


# revision identifiers, used by Alembic.
revision = '91fa482ba2b4'
down_revision = 'dc736d1268df'
branch_labels = None
depends_on = None


def upgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.add_column('users', sa.Column('otp', sa.String(length=6), nullable=True))
    op.add_column('users', sa.Column('verifiedEmail', sa.String(length=5), nullable=True))
    # ### end Alembic commands ###


def downgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    op.drop_column('users', 'verifiedEmail')
    op.drop_column('users', 'otp')
    # ### end Alembic commands ###